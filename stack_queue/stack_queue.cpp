#include "stack_queue.h"
using namespace std;

void Sta_Que::appendTail(int value)
{
	//��value��ջista1
	ista1.push(value);
}
int Sta_Que::deleteHead()
{
	//�ж�ista2�Ƿ�Ϊ�ǿ�,�ǿյĻ�����ista2ջ��Ԫ�أ�ista2ջ��Ԫ�س�ջ��
	if (!ista2.empty()) 
	{
		int tmp = ista2.top();
		ista2.pop();
		return tmp;
	}

	//�ж�ista1�Ƿ�Ϊ�գ�Ϊ�շ���-1
	if (ista1.empty()) 
		return -1;
	//ѭ��ista1(ista1�ǿ�),��ista1��ջ��Ԫ�س�ջ��Ȼ����ջista2
	while (!ista1.empty()) {
		int tmp = ista1.top();
		ista1.pop();
		ista2.push(tmp);
	}
	//����ista2ջ��Ԫ�أ�ista2ջ��Ԫ�س�ջ��
	int tmp = ista2.top();
	ista2.pop();
	return tmp;
}
