#include "mysqlTest.h"
using namespace std;
using namespace appQuick;

DB_MySql::DB_MySql(const Information* aInf)
{
    mysql = new MYSQL;
    res = nullptr;
    column = nullptr;
    Connect(aInf);
}

DB_MySql::~DB_MySql()
{
    mysql_free_result(res);
    mysql_close(mysql);
}

bool DB_MySql::Connect(const Information* aInf)
{
   
    //初始化mysql
     mysql_init(mysql);

     if(mysql==NULL)
        return false;

     //连接参数（初始化mysql返回的句柄，ip地址，用户名，密码，数据库名，端口号）
     if(mysql_real_connect(mysql, aInf->ip, aInf->name, aInf->password, aInf->database_name, aInf->port, NULL, 0))
     {  
        //返回连接成功
        mysql_query(mysql, "set names utf8"); //把要执行的sql语句、 返回的结果 转换成utf8  
        LOGI("Connected succeed Mysql\n");
        return true;
     }
    else
    {   
        //返回连接失败，失败日志
        LOGI("Error connecting to database:%s\n",mysql_error(mysql));
        return false;
    }

}

bool DB_MySql::execSql(const CString & aSql)
{
    if(mysql==NULL)
      return false;

    //获取aSql参数的字符串
	CStringA lsql = aSql.AsAnsi().c_str();

    //返回0 查询成功，返回1查询失败 
    if (mysql_query(mysql, lsql.c_str()))    //执行SQL语句
    {
        LOGI("Query failed (%s)\n", mysql_error(mysql));
        return false;
    }
    else
    {
        LOGI("Execute successfully");
	    return true;
    }
}

bool DB_MySql::querysql(const CString & aSql)
{
    //判断mysql句柄是否为空
    if(mysql==NULL)
        return -1; 

    //获取sql语句
    CStringA lsql = aSql.AsAnsi().c_str();
    
    //执行sql语句
    execSql(lsql.c_str());
    
    //获得sql语句结束后返回的结果集
    res = mysql_store_result(mysql);
    if (!res)   
    {
        LOGI("Couldn't get result from %s\n", mysql_error(mysql));
        return false;
    }

    int field = mysql_num_fields(res);//获取结果集的列数
     //mysql_num_rows(res)  获取结果集的行数
 
    //定义一个存储字段名的数组
    vector<string> lName;
    string lSumText;

    //循环往数组添加字段名
    for(int i=0; i<field; i++)
    {   
        
        lName.push_back(mysql_fetch_field(res)->name);
        //mysql_fetch_field()  获取字段名
    }


    while (column = mysql_fetch_row(res)) //获得每一行的内容,并自动跳到下一行
    {   
        lSumText="";
        //循环打印每行的内容
        for (int i = 0; i < field; i++)
        {   
           string lFiledName = lName[i]; //获取字段名
           string lValue = column[i]; //column是列数组  获取字段值  
            if(i!=field-1)
            {
                lSumText = lSumText+lFiledName +" : "+lValue+" , ";
            }
            else
            {
                lSumText = lSumText+lFiledName +" : "+lValue;
            }
        }   

        LOGI("%s",lSumText.c_str());
    }


    return true;

}

void DB_MySql::insertsql(const CString& satabname,vector<vector<void*> > & vaData)
{



}

void DB_MySql::updatesql(const CString& satabname, vector<vector<void*> >& vaData)
{


}

 void DB_MySql::deletesql(const CString& satabname, const CString& sawheretext)
 {

 }

void DB_MySql::DataBeseTest()
{
    //sqltest->Connect("localhost", "root", "", "test", 3306);
    //sqltest->querysql("Person");
    
}