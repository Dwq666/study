#ifndef SEARCH_BACK_H
#define SEARCH_BACK_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    //从上到下打印二叉树
    vector<int> levelOrder(TreeNode *root);
    


#endif
