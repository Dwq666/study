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
	* ������ջʵ��һ������
	���е��������£�
	�ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�
	(��������û��Ԫ�أ�deleteHead�������� -1)
	   ista1 ջ1   �� ista2  ջ2

	   ˼·��

	*/
	void appendTail(int value);
	int deleteHead();








};






#endif