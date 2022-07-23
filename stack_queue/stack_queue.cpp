#include "stack_queue.h"
using namespace std;

/*
	* 用两个栈实现一个队列
	* 队列的声明如下，请实现它的两个函数appendTail(int value)和deleteHead()
	* 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead()操作返回 -1
	* ista1 栈1 ， ista2 栈2
	*/

void Sta_Que::appendTail(int value)
{
	//ista1添加元素
	ista1.push(value);
}
int Sta_Que::deleteHead()
{
	//判断ista2是否为非空，非空的话就返回ista2栈顶元素，ista2栈顶元素出栈
	if (!ista2.empty()) 
	{
		int tmp = ista2.top();
		ista2.pop();
		return tmp;
	}

	//判断ista1是否为空，空的话返回-1
	if (ista1.empty()) 
		return -1;

	//循环ista1（ista1非空），获取ista1栈顶元素，获取到的元素入栈ista2，ista1栈顶元素出栈
	while (!ista1.empty()) {
		int tmp = ista1.top();
		ista1.pop();
		ista2.push(tmp);
	}
	//返回ista2栈顶元素，ista2栈顶元素出栈
	int tmp = ista2.top();
	ista2.pop();
	return tmp;
}


/*
	* 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中
	* 调用 stamin、stapush 及 stapop 的时间复杂度都是 O(1）
	* ista1 栈1 ， ista2 栈2
	*/

void Sta_Que::stapush(int x)
{	
	//ista1入栈x，如果 ista2为空 或 ista2栈顶元素小于x,ista2入栈x
	ista1.push(x);
	if (ista2.empty() || ista2.top() >= x)
		ista2.push(x);
}
void Sta_Que::stapop()
{
	//如果ista1栈顶元素=ista2栈顶元素，ista2栈顶元素出栈，ista1栈顶元素出栈
	if (ista1.top() == ista2.top())
		ista2.pop();
	ista1.pop();
}
int Sta_Que::statop()
{	
	return ista1.top();
}
int Sta_Que::stamin()
{
	return ista2.top();
}