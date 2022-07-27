#include <iostream>
#include "Sql/ConnectionSql.h"
using namespace std;



int main() 
{  
   //获取连接sql信息
    Information * inf = new Information("localhost", "root", "", "test", 3306);
    //连接sql
    //DB_sql* ldb = Connection::it()->Connec("mysql",inf);  

    vector<vector<void *> > vlData;
	vlData.push_back({"name","age"});
	vlData.push_back({"ccc","100"});
    vlData.push_back({"ddd","200"});
    //ldb->insertsql("person",vlData);
    //ldb->querysql("select * from person");

    
    system("pause");

    return 0;
}