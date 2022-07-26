#include <iostream>
#include "Sql/ConnectionSql.h"
using namespace std;

int main() 
{  
   
    Information * inf=new Information("localhost", "root", "", "test", 3306);
    
     DB_sql* a = Connection::Connec("MySql",inf);   

    a->querysql("select * from person");


    
    system("pause");

    return 0;
}