#ifndef MYSQLTEST_H
#define MYSQLTEST_H

#include <mysql.h>
#include "core/aqCore.h"
#include <vector>
using namespace std;
using namespace appQuick;

class DataBese
{
public:
    DataBese();
    virtual ~DataBese();
    
    //连接数据库 参数为ip 用户名 密码 数据库名 端口
    bool Connect(const char* ip, const char* name, const char* cypher, const char* database_name, const int port);
    //执行sql语句  参数为sql语句
    bool execsql(const CString & aSql);
    //查询表  参数为表名
    bool Query(const CString& table_name);




private:
    MYSQL* mysql;  //mysql连接  
    MYSQL_RES* res;//这个结构代表返回行的一个查询结果集  
    MYSQL_ROW column;//  一个字符串数组


public:
    //测试
    void DataBeseTest();

};




#endif