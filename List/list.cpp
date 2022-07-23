#include "list.h"
using namespace std;

/*
* 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
*  head (链表型参数)
*/

vector<int> ListSolution::reversePrint(ListNode* head)
{	
	//定义一个栈ista
	stack<int> ista;
	//循环链表head（head非空）
	while (head != NULL)
	{	
		//,链表当前节点val入栈
		ista.push(head->val);
		//next指向下一个节点
		head = head->next;
	}

	//定义一个数组ivec
	vector<int> ivec;
	//循环栈ista（ista非空），
	while (!ista.empty())
	{	
		//	把ista栈顶元素添加到数组ivec
		ivec.push_back(ista.top());
		//ista栈顶元素出栈
		ista.pop();
	}
	//返回数组ivec
	return ivec;
}



/*
* 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点
*/

ListNode* ListSolution::reverseList(ListNode* head)
{
	ListNode* cur = head, * pre = nullptr;
	while (cur != nullptr) {
		ListNode* tmp = cur->next; // 暂存后继节点 cur.next
		cur->next = pre;           // 修改 next 引用指向
		pre = cur;                 // pre 暂存 cur
		cur = tmp;                 // cur 访问下一节点
	}
	return pre;
}

/*
* 请实现copyRandomList(ListNode* head)函数，
* 复制一个复杂链表。在复杂链表中，每个节点除了有一个next指针指向下一个节点，还有一个random指针指向链表中的任意节点或者 null
* 
*/

ListNode* ListSolution::copyRandomList(ListNode* head)
{
	if (head == nullptr) 
		return nullptr;
	//定义一个链表cur = head
	ListNode* cur = head;
	//定义一个哈希数组lmap
	map<ListNode*, ListNode*> lmap;
	//循环cur链表（cur非空）
	while (cur != nullptr)
	{	
		//建立一个新节点，并往lmap增加 key value 值
	    lmap[cur] = new ListNode(cur->val);
		cur = cur->next;
	}

	cur = head;
	while (cur != nullptr)
	{	
		//修改新链表的指向
		lmap[cur]->next = lmap[cur->next];
		lmap[cur]->random = lmap[cur->random];
		cur = cur->next;
	}
	//返回新链表的头
	return lmap[head];
}