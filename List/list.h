#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include<map>
using namespace std;

struct ListNode
{	
	int val;
	ListNode* next;
	ListNode* random;
	ListNode(int x)
	{
		val = x;
		next = NULL;
		random = NULL;
	}

};

class ListSolution
{
public:


	/*
	* 从尾到头打印链表
	*/
	vector<int> reversePrint(ListNode* head);
	

	/*
	* 反转链表
	*/
	ListNode* reverseList(ListNode* head);


	/*
	* 复杂链表的复制
	*/
	ListNode* copyRandomList(ListNode* head);

};




#endif