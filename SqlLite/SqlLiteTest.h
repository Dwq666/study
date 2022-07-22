/*==========================================================
*
*  APPQuick 原生跨平台开发框架
*
*  A low-code native cross-platform development framework encapsulating 
*   most operating system underlying APIs and Kia graphics engines
*
*  一套封装了大多数操作系统底层API和Skia图形引擎的低代码原生跨平台开发框架
*
*  SqlLiteTest.h
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
#ifndef SQLLITETEST_H_
#define SQLLITETEST_H_

#include <iostream>
#include "db/MTable/MTable.h"
#include "db/customdb.h"
#include "ext/sqlite3.h"
#include "db/serverTable.h"
#include "db/Query.h"

using  namespace appQuick;
using  namespace db;

namespace appQuick {

namespace db {

class SqlLiteTest
{
public:
	sqlite3 * mdb;
	CString sdbFile;
	CString sPath;

public:
	SqlLiteTest();
	virtual ~SqlLiteTest();
	virtual bool Connect(const CString & aFileName);//连接数据库
	virtual bool isTable(); //判断数据表是否存在 
	virtual bool execSql(const CString & aSql);//执行sql语句
	virtual void querysql(const CString & aSql);//查询sql语句
	virtual void insertsql(const CString & satabname,vector<vector<void  *> > & vaData);//插入语句
	virtual void updatesql(const CString& satabname, vector<vector<void*> >& vaData);//更新语句
	virtual void deletesql(const CString& satabname, const CString& sawheretext);
	virtual void createTablesql(const CString& atabname, vector<vector<void*> >& aData);

public:
	void Sqllitetest();


};


}
}




#endif /* SQLLITETEST_H_ */
