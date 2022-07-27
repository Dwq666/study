#ifndef MYSQLTEST_H
#define MYSQLTEST_H

#include "SqlForeign.h"
#include <mysql.h>
#include <vector>
using namespace std;
using namespace appQuick;

class DB_MySql:public DB_sql
{
public:
    DB_MySql(const Information* aInf);
    virtual ~DB_MySql();
    
    //连接数据库 参数为ip 用户名 密码 数据库名 端口
    virtual bool Connect(const Information* aInf);
    //执行sql语句  参数为sql语句
    virtual bool execSql(const CString & aSql);
    //查询表  参数为表名
    virtual bool querysql(const CString & aSql);
    virtual void insertsql(const CString& satabname,vector<vector<void*> > & vaData);//插入语句
	virtual void updatesql(const CString& satabname, vector<vector<void*> >& vaData);//更新语句
    virtual void deletesql(const CString& satabname, const CString& sawheretext);//删除语句




private:
    MYSQL* mysql;  //mysql连接  
    MYSQL_RES* res;//这个结构代表返回行的一个查询结果集  
    MYSQL_ROW column;//  一个字符串数组


public:
    //测试
    void DataBeseTest();

};




#endif