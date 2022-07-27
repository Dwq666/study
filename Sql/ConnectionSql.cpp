#include "ConnectionSql.h"
using namespace std;

dbManager::dbManager(dbType aType,const Information* aInf)
{
    //设置参数
}

dbManager::~dbManager()
{


}

//跟据aType参数不同，选择连接
DB_sql* dbManager::GetConnec()
{   
    //判断有没有连接池里面有没有可用，如果有直接取一条，返回
    DB_sql* ldb = mConnects.pop_back();
    if (ldb!=NULL)
        return  ldb;
    //没有，新建一个连接
    if( iType == dbt_mySql)
      //连接mysql
       ldb = new DB_MySql(mOption);   
    else if(iType == dbt_sqlLite)
        //连接sqllite
       ldb = new SqlLiteTest(mOption); 
       
    return ldb;
}

void closeConnect(DB_sql * aConn)
{
    mConnects.push(aConn)
    //放到链表
}