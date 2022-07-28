#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

class search_Algorithm
{
public:

	/*
	*  数组中重复的数字
	*/
	vector<int> findRepeatNumber(vector<int>& nums);


	/*
	* 	在排序数组中查找数字 I
	*/
	int search(vector<int>& nums, int target);
	int helper(vector<int>& nums, int tar);


	/*
	* 0～n-1 中缺失的数字
	*/
	int missingNumber(vector<int>& nums);



	/*
	*  二维数组中的查找
	*/
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);


	/**
	 * 旋转数组的最小数字
	 * 
	 */

	int minArray(vector<int>& numbers);
	


	/**
	 * 第一个只出现一次的字符
	 * 
	 */

	 char firstUniqChar(string s);
	

};









#endif
