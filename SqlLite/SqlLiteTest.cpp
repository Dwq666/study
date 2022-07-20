/*==========================================================
*
*  APPQuick 原生跨平台开发框架
*
*  A low-code native cross-platform development framework encapsulating 
*   most operating system underlying APIs and Kia graphics engines
*
*  一套封装了大多数操作系统底层API和Skia图形引擎的低代码原生跨平台开发框架
*
*  SqlLiteTest.cpp
*
*  Created on: 2022年7月15日
*  Author: Daly
*  
*  版权所有:深圳市微方创业科技有限公司  
*  CopyRight:Microsquare Innovative Technology co. 
*  
*  The Creative Commons  License (CC) 
*  
*  Permission is hereby granted ,to any person obtaining a
*  copy of this software and associated documentation files
*  to can be use, copy, modify, merge, publish, distribute,
*  but not for commercial purposes.
*  
*  本框架即时授予CC License ,可以被修改，分发，复制，但不能用于商业用途
*  
*  
*==========================================================
*/
#include "SqlLiteTest.h"
#include "gdi/message.h"
#include "db/aqdb.h"
#include "db/jsondata.h"
#include "core/uid.h"
#include "gdi/Picture.h"
#include "core/base64.h"
#include "ext/json/json.h"
#include "string"
using  namespace appQuick;
using  namespace db;
using  namespace std;

SqlLiteTest::SqlLiteTest()

{
	mdb=NULL;

}

SqlLiteTest::~SqlLiteTest()
{
	if (mdb!=NULL)
	sqlite3_close(mdb);

}


bool SqlLiteTest::Connect(const CString & aFileName)
{
	if (mdb!=NULL)
       sqlite3_close(mdb);

	//打开数据库，连接数据库
	int rc = sqlite3_open(aFileName.AsAnsi().c_str(), &mdb);
	if( rc )
	{
		//连接数据库失败
		LOGI("Can't open database: %s\n", sqlite3_errmsg(mdb));
		sqlite3_close(mdb);
		mdb=NULL;
	}
	else
	{
		//连接数据库成功
		LOGI("Opened database successfully " );
	}

	//初始化，判断是否有数据表存在,不存在就创建
	 isTable();



	return rc;
}

//初始化，判断是否有数据表存在,不存在就创建
bool SqlLiteTest::isTable()
{

	Json::Reader reader;
	Json::Value root;


	//读取json文件，解析json文件
	int aSize=0;
	CString lText;
	BYTE * lData = FileUtil::LoadDataFromFile("E:/sqlliteTest.json", aSize);
	CStringA lStr(lData,aSize);
	if (reader.parse(lStr.c_str(), root))
	{
		int lSize=root.size();
		for(int i=0;i<lSize;i++)
		  {
		     Json::Value lNode = root[i];
		     //获取teblename数据，得到数据表名
		     CStringA lText=lNode["tablename"].asString().c_str();
		     //拼装sql语句
		     CStringA sText= CStringA("")+"select * from "+lText+"\0";
		     //根据数据表名判断是否在数据库存在
		     if(execSql(sText.c_str()))
		     {
		    	  LOGI("数据表存在");

		     }
		     else
		    //数据表不存在,创建数据表
		     {

		    	 LOGI("数据表不存在,开始创建数据表");

		    	 CStringA fieldname;
		    	 CStringA datattype;
		    	 CStringA sqlsum;
		    	 //获取fields数组数据
		    	 const Json::Value arrayObj = lNode["fields"];
		    	 for (int j=0; j<arrayObj.size(); j++)
		    	 {

		    		 //循环数组获取fieldname，datattype数据，得到字段名称，字段类型
		    	 	 fieldname = arrayObj[j]["fieldname"].asString().c_str();
		    	 	 datattype = arrayObj[j]["datattype"].asString().c_str();
		    	 	 //拼接字段名和类型
		    	 	 if(j!=arrayObj.size()-1)
		    	 	 {
		    	 		sqlsum = sqlsum+CStringA("")+fieldname.c_str()+" "+datattype.c_str()+",";
		    	 	 }
		    	 	 else
		    	 	 {
		    	 		sqlsum = sqlsum+CStringA("")+fieldname.c_str()+" "+datattype.c_str();
		    	 	 }

		    	 }

		    	//拼装sql语句，创建数据表
		    	 CStringA lsql=CStringA("")+"create table "+lText.c_str()+"("+sqlsum.c_str()+")"+"\0";
		    	 execSql(lsql.c_str());
		    	 LOGI("创建成功");

		     }

		  }

	}


	return 1;

}

//执行sql语句
bool SqlLiteTest::execSql(const CString & aSql)
{
	if (mdb==NULL)
	  return false;

	//获取aSql参数的字符串
	CStringA lsql = aSql.AsAnsi().c_str();

	char *zErrMsg = NULL;

	//
	int ret = SQLITE_OK;
	//执行sql语句
   ret = sqlite3_exec(mdb, lsql.c_str(), NULL, NULL, &zErrMsg);
   if(ret != SQLITE_OK)
   {
	   //失败返回错误日志
	   LOGI("Error SQL: %s \n", zErrMsg);
	   sqlite3_free(zErrMsg);
	   return false;
   }
   else
   {
	   LOGI("Execute successfully");
	   return true;
   }


}



void SqlLiteTest::querysql(const CString & aSql)
{

  sqlite3_stmt *stmt = NULL;
  //转换sql语句
  int rc  = sqlite3_prepare(mdb,aSql.AsAnsi().c_str(),-1,&stmt,NULL);
  //获取栏位数
  int n_columns = sqlite3_column_count(stmt);
  //查询数据
  rc = sqlite3_step(stmt);

  string lText("[ \r\n");

  while (rc==SQLITE_ROW)
  {
	 lText +="\t{" ;
	 for (int i = 0; i < n_columns; i++)
	  {
		 //获取 第i列 的字段名称
          string  lFieldName = sqlite3_column_name(stmt,i);
          //获取 第i列 的字段值
          string  lValue = (const char *) sqlite3_column_text(stmt,i);

          //拼接json语句,判断是否为最后一列
          if(i!=n_columns-1)
          {
        	  lText += "\""+lFieldName+"\" : \""+lValue+"\" , ";
          }
          else
          {
        	  lText += "\""+lFieldName+"\" : \""+lValue+"\"";

          }
	  }

	 //跳到下一行数据行
	 rc = sqlite3_step(stmt);


	 //判断是否为最后一行数据行
	 if(rc!=SQLITE_ROW)
	 {
		 lText +="}\r\n" ;
	 }
	 else
	 {
		 lText +="},\r\n" ;
	 }

  }

  lText +="]";
  //将查询到的数据放到json文件中
  FileUtil::SaveDataToFile("E:/jsonTest.json",(BYTE *)lText.c_str(),strlen(lText.c_str()));

}



void SqlLiteTest::insertsql(const CString& aSql, vector<vector<void *> >& lData)
{

	CStringA tabname = aSql.AsAnsi().c_str();


	vector<vector<void *> > lvec = lData;

	string aText;  
	string lText1 ; 
	string lText2 ;
	for (int i = 0; i < lvec.size(); i++)
	{	
		lText1 = "(";
		lText2 = "(";
		vector<void *> cvec = lvec[i];
		for (int j = 0; j < cvec.size(); j++)
		{	
			
			if (j != cvec.size() - 1)
			{
				lText1 = lText1 + (char *)cvec[j] + ",";
				lText2 = lText2 + (char*)cvec[j] + ",";
			}
			else
			{
				lText1 = lText1 + (char*)cvec[j]+")";
				lText2 = lText2 + (char*)cvec[j]+")";
			}

			}
			
		if (i == 0)
		{
			aText = lText1;
			lText2 = "";
		}
		if (i > 0)
		{
			LOGI("%s  %s", aText.c_str(), lText2.c_str());
		}
		
		}
		//CStringA lText3 = CStringA("") + " insert into " + tabname.c_str() + " " + lText1.c_str() + " " + "values" + lText2.c_str() + ";";
		//LOGI(" %s ", lText3.c_str());
	
	
	}













void SqlLiteTest::Sqllitetest()
{
	SqlLiteTest sqltest;
	//sqltest.Connect("E:/sqlliteTest.db");


	CString ltest="SqlLiteTest";
	//sqltest.querysql(ltest);
	vector<vector<void *>>    lData;
	lData.push_back({"name","age"});
	lData.push_back({"张三","19"});
	lData.push_back({"李四","18"});


	sqltest.insertsql(ltest,lData);

	/*for (int i=0;i<lData.size();i++)
	{
		lText="";
		vector<const char*> ll=lData[i];
		for (int j=0;j<ll.size();j++)
		{
			lText = lText+ "\t" + ll[j];
		}
	
	}*/

	/*for (vector<vector<const char*>>::iterator iter = lData.begin(); iter != lData.end(); iter++)
	{
		lText = "";
		vector<const char*> vec_temp = *iter;
		for (vector<const char*>::iterator it = vec_temp.begin(); it != vec_temp.end(); it++)
		{
			lText = lText +"\t"+ * it;

		}


		LOGI(" %s", (lText + "\r\n").c_str());

	}*/

	




	//insert into 10 条数据

	//insert ( 表名 ， 字段/ 值  数组  ，条件)

	//update ( 表名 ， 字段/ 值  数组  ，条件)

	//sqltest.querysql("select * from MyTable_2");


    //delete  指定条件


	//query （表名 条件）

	//create table tablename   字段/ 值






}
