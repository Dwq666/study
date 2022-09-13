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

struct TreeNode1
{
    int val;
    TreeNode1 *left;
    TreeNode1 *right;
    TreeNode1() : val(0), left(nullptr), right(nullptr) {}
    TreeNode1(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode1(int x, TreeNode1 *left, TreeNode1 *right) : val(x), left(left), right(right) {}
};

//从上到下打印二叉树
vector<int> levelOrder(TreeNode *root);

//从上到下打印二叉树 II
vector<vector<int>> levelOrder2(TreeNode *root);

//从上到下打印二叉树 III
vector<vector<int>> levelOrder3(TreeNode *root);

//树的子结构
bool isSubStructure(TreeNode *A, TreeNode *B);
bool recur(TreeNode *A, TreeNode *B);

// 二叉树的镜像
TreeNode *mirrorTree(TreeNode *root);

//对称的二叉树
bool isSymmetric(TreeNode *root);
bool symmetry(TreeNode *L, TreeNode *R);

//矩阵中的路径
int rows, cols;
bool exist(vector<vector<char>> &board, string word);
bool dfs(vector<vector<char>> &board, string word, int i, int j, int k);

//机器人的运动范围
int movingCount(int m, int n, int k);
int dfsmovingCount(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k);

//二叉树中和为某一值的路径
vector<vector<int>> res;
vector<int> path;
vector<vector<int>> pathSum(TreeNode1 *root, int target);
void recurPathSum(TreeNode1 *root, int tar);
#endif
