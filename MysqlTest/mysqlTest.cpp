#include "mysqlTest.h"
using namespace std;

DataBese::DataBese()
{
    mysql = NULL;
    state = false;

}

DataBese::~DataBese()
{
    mysql_close(mysql);
}

bool DataBese::Connect(const char* ip, const char* name, const char* cypher, const char* database_name, const int port)
{
   
    //初始化mysql
     mysql_init(mysql);

     //连接参数（初始化mysql返回的句柄，ip地址，用户名，密码，数据库名，端口号）
     if(mysql_real_connect(mysql, ip, name, cypher, database_name, port, NULL, 0))
     {  
        //返回连接成功
        printf("Connected succeed\n");
        return true;
     }
    else
    {   
        //返回连接失败，失败日志
        printf("Error connecting to database:%s\n",mysql_error(mysql));
        return false;
    }

}


void DataBese::DataBeseTest()
{
    DataBese sqltest;
    sqltest.Connect("localhost", "root", "123456", "test", 3306);

   

}