#include "stack_queue.h"
using namespace std;

void Sta_Que::appendTail(int value)
{
	//将value入栈ista1
	ista1.push(value);
}
int Sta_Que::deleteHead()
{
	//判断ista2是否为非空,非空的话返回ista2栈顶元素，ista2栈顶元素出栈，
	if (!ista2.empty()) 
	{
		int tmp = ista2.top();
		ista2.pop();
		return tmp;
	}

	//判断ista1是否为空，为空返回-1
	if (ista1.empty()) 
		return -1;
	//循环ista1(ista1非空),将ista1的栈顶元素出栈，然后入栈ista2
	while (!ista1.empty()) {
		int tmp = ista1.top();
		ista1.pop();
		ista2.push(tmp);
	}
	//返回ista2栈顶元素，ista2栈顶元素出栈，
	int tmp = ista2.top();
	ista2.pop();
	return tmp;
}
