#ifndef CONNECTIONSQL_H
#define CONNECTIONSQL_H


#include "mysqlTest.h"
#include "SqlLiteTest.h"
#include <stack>
using namespace appQuick;
using namespace std;


enum dbType  //数据文件格式
{
   dbt_mySql, 
   dbt_sqlLite   
};


//数据库管理
class dbManager
{
public:
    stack<DB_sql *> mConnects;  //未连接列表，可用表
public:
    dbType iType;
    const Information * mOption;     
public:
    dbManager(dbType aType,const Information* aInf);
    //根据传入参数，选择连接
    DB_sql * GetConnec();
    //释放返回到数组
    void closeConnect(DB_sql * aConn); 
public:
    ~dbManager();
private:
};









#endif