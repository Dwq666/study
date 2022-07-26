#ifndef SQLFOREIGN_H
#define SQLFOREIGN_H

#include <iostream>
#include "core/aqCore.h"
using namespace appQuick;
using namespace std;

//数据连接类
class Information
{   
public:
    Information(const char* ip, const char* name, const char* cypher, const char* database_name, int port)
    {
        this->ip = ip;
        this->name = name;
        this->password=password;
        this->database_name=database_name;
        this->port=port;
    }

    
public:
    //ip地址
    const char* ip;
     //用户名
    const char* name; 
     //密码
    const char* password; 
     //数据库名
    const char* database_name; 
     //端口号
     int port;

};



class DB_sql
{

public:
    virtual bool execSql(const CString & aSql)=0;//执行语句
    virtual bool querysql(const CString & aSql)=0;//查询sql语句
    virtual void insertsql(const CString& satabname,vector<vector<void*> > & vaData)=0;//插入语句
	virtual void updatesql(const CString& satabname, vector<vector<void*> >& vaData)=0;//更新语句
    virtual void deletesql(const CString& satabname, const CString& sawheretext)=0;//删除语句
};











#endif