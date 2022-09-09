#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

//斐波那契数列
int fib(int n);

//青蛙跳台阶问题
int numWays(int n);

//股票的最大利润
int maxProfit(vector<int> &prices);

//连续子数组的最大和
int maxSubArray(vector<int> &nums);

//礼物的最大价值
int maxValue(vector<vector<int>> &grid);

//把数字翻译成字符串
int translateNum(int num);

//最长不含重复字符的子字符串
int lengthOfLongestSubstring(string s);

#endif