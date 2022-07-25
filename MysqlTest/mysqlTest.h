#ifndef MYSQLTEST_H
#define MYSQLTEST_H

#include <iostream>
#include <Windows.h>
#include <WinSock.h>
#include <mysql.h>

using namespace std;

class DataBese
{
public:
    DataBese();
    virtual ~DataBese();
    
    //连接数据库 参数为ip 用户名 密码 数据库名 端口
    bool Connect(const char* ip, const char* name, const char* cypher, const char* database_name, const int port);





private:
    MYSQL* mysql;  //mysql连接  
    bool state;   //连接状态 true为已连接
    


public:
    //测试
    void DataBeseTest();

};




#endif