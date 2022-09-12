#ifndef DOUBLE_POINTER_H
#define DOUBLE_POINTER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//删除链表的节点
ListNode *deleteNode(ListNode *head, int val);

//链表中倒数第 k 个节点
ListNode *getKthFromEnd(ListNode *head, int k);

//合并两个排序的链表
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

//两个链表的第一个公共节点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

//调整数组顺序使奇数位于偶数前面
vector<int> exchange(vector<int> &nums);

//调整数组顺序使奇数位于偶数前面
vector<int> exchange(vector<int> &nums);

//和为 s 的两个数字
vector<int> twoSum(vector<int> &nums, int target);

//翻转单词顺序
string reverseWords(string s);

#endif