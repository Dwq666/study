#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

#include "core/aqcore.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Sta_Que
{

private:
	stack<int> ista1, ista2;


public:


	/*
	* 用两个栈实现一个队列
	队列的声明如下，
	分别完成在队列尾部插入整数和在队列头部删除整数的功能。
	(若队列中没有元素，deleteHead操作返回 -1)
	   ista1 栈1   ， ista2  栈2

	   思路：

	*/
	void appendTail(int value);
	int deleteHead();








};






#endif