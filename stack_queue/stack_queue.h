#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H


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
	*/
	void appendTail(int value);
	int deleteHead();


	/*
	* 包含 min 函数的栈
	*/
	void stapush(int x);
	void stapop();
	int statop();
	int stamin();





};






#endif