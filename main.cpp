#include <iostream>
#include "SortMain/SortMain.h"
#include "SqlLite/SqlLiteTest.h"
#include "Stack_Queue/stack_queue.h"
#include "List/list.h"
using namespace std;

int main() 
{  
   

    //Sqllite函数测试
    //SqlLiteTest Test;
    //Test.Sqllitetest();
    
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(8);
    n1->next = n2;
    n2->next = n3;

    ListSolution listtest;
    ListNode* a = listtest.reverseList(n1);
    
    while (a != nullptr)
    {
        cout << a->val << endl;
        a = a->next;
    }
  
    system("pause");

    return 0;
}