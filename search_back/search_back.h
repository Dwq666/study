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

    //从上到下打印二叉树 II
    vector<vector<int> > levelOrder2(TreeNode *root);

    //从上到下打印二叉树 III
    vector<vector<int> > levelOrder3(TreeNode *root);

    //树的子结构
    bool isSubStructure(TreeNode* A, TreeNode* B);
    bool recur(TreeNode* A, TreeNode* B);
    


#endif
