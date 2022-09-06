#include "search_back.h"

/**
 * @brief 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 *
 * @param root 二叉树数据结构
 * @return vector<int>
 */
vector<int> levelOrder(TreeNode *root)
{
    vector<int> iRes;       //定义打印数组
    queue<TreeNode *> mQue; //插入二叉树值的队列

    if (!root)
        return iRes;

    mQue.push(root);

    while (!mQue.empty())
    {
        TreeNode *node = mQue.front();
        mQue.pop();

        iRes.push_back(node->val);

        if (node->left != nullptr)
            mQue.push(node->left);
        if (node->right != nullptr)
            mQue.push(node->right);
    }   
   
    return iRes;
}