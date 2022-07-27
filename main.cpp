#include <iostream>
#include "Sql/ConnectionSql.h"
using namespace std;



int main() 
{  
   //获取连接sql信息
    Information * inf = new Information("localhost", "root", "", "test", 3306);
    //连接sql
    //DB_sql* ldb = Connection::it()->Connec("mysql",inf);  

    dbManager * dbman = new dbManager(dbt_mySql,inf);

    vector<vector<void *> > vlData;
	vlData.push_back({"name","age","address"});
	vlData.push_back({"ccc","100","福建"});
    vlData.push_back({"ddd","200","泉州"});
    //ldb->insertsql("person",vlData);
        
    DB_sql* ldb = dbman->GetConnec();        
    ldb->querysql("select * from person");
    dbman->closeConnect(ldb);    

    delete(inf);
    delete(dbman);
    



    system("pause");

    return 0;
}