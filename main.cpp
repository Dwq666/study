#include <iostream>
#include "SortMain/SortMain.h"
#include "SqlLite/SqlLiteTest.h"
#include "Stack_Queue/stack_queue.h"
#include "List/list.h"
#include "String/string.h"
#include "Search/search.h"
using namespace std;

int main() 
{  
   

    //Sqllite函数测试
    //SqlLiteTest Test;
    //Test.Sqllitetest();
    
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(1);
    a.push_back(0);
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(4);



    search_Algorithm b;
    cout << b.search(a, 4) << endl;
    
    system("pause");

    return 0;
}