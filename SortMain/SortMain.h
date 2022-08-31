#ifndef SORTMAIN_H
#define SORTMAIN_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <cmath>
using namespace std;

class Sort_Algorithm
{

public:
	// 1 选择排序.
	void sort_select(vector<int> &data);

	// 2 插入排序.
	void sort_insert(vector<int> &data);

	// 3 冒泡排序.
	void sort_bubble(vector<int> &data);

	// 4.1 快速排序-递归实现.
	void sort_quick_recursive(std::vector<int> &data, int left, int right);
	int partition(std::vector<int> &data, int left, int right);

	// 4.2 快速排序-非递归实现
	void sort_quick_Norecursive(std::vector<int> &data, int left, int right);

	// 5  希尔排序
	void sort_shell(vector<int> &data);

public:
	void functionTest();
};

#endif // SORTMAIN_H