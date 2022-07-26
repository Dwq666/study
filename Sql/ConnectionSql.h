#ifndef CONNECTIONSQL_H
#define CONNECTIONSQL_H

#define ms "MySql"
#define sl "SqlLite"

#include <iostream>
#include "core/aqCore.h"
#include "mysqlTest.h"
using namespace appQuick;
using namespace std;


class Connection
{
public:
    Connection();
    ~Connection();
    static DB_sql* Connec(const char * aType,const Information* aInf)
    {   
        DB_sql* a;
        if(aType == ms)
        a = new DB_MySql(aInf);            
        return a;
    }
};




#endif