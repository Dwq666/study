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

    // root为空返回 ""
    if (!root)
        return iRes;

    //队列mQue添加root
    mQue.push(root);

    while (!mQue.empty())
    {
        //取到队列的队首
        TreeNode *node = mQue.front();
        //队首出队
        mQue.pop();

        //将值添加到数组
        iRes.push_back(node->val);

        //添加左子节点和右子节点到队列
        if (node->left != nullptr)
            mQue.push(node->left);
        if (node->right != nullptr)
            mQue.push(node->right);
    }

    return iRes;
}

/**
 * @brief 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
 *
 * @param root 二叉树数据结构
 * @return vector<vector<int>>
 */
vector<vector<int>> levelOrder2(TreeNode *root)
{
    vector<vector<int>> iRes; //定义打印数组
    queue<TreeNode *> mQue;   //插入二叉树值的队列

    // root为空返回 ""
    if (!root)
        return iRes;

    //队列mQue添加root
    mQue.push(root);

    while (!mQue.empty())
    {
        vector<int> itmp;
        for (int i = mQue.size(); i > 0; --i)
        {
            TreeNode *node = mQue.front();
            mQue.pop();
            //添加左子节点和右子节点到队列
            itmp.push_back(node->val);
            if (node->left != nullptr)
                mQue.push(node->left);
            if (node->right != nullptr)
                mQue.push(node->right);
        }
        iRes.push_back(itmp);
    }
    return iRes;
}

/**
 * @brief 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 *
 * @param root 二叉树数据结构
 * @return vector<vector<int> >
 */
vector<vector<int>> levelOrder3(TreeNode *root)
{
    deque<TreeNode *> mDeq;
    vector<vector<int>> iRes;
    if (!root)
        return iRes;
    mDeq.push_back(root);
    while (!mDeq.empty())
    {
        // 打印奇数层
        vector<int> tmp;
        for (int i = mDeq.size(); i > 0; i--)
        {
            // 从左向右打印
            TreeNode *node = mDeq.front();
            mDeq.pop_front();
            tmp.push_back(node->val);
            // 先左后右加入下层节点
            if (node->left != nullptr)
                mDeq.push_back(node->left);
            if (node->right != nullptr)
                mDeq.push_back(node->right);
        }

        iRes.push_back(tmp);
        // 若为空则提前跳出
        if (mDeq.empty())
            break;

        // 打印偶数层
        tmp.clear();
        for (int i = mDeq.size(); i > 0; i--)
        {
            // 从右向左打印
            TreeNode *node = mDeq.back();
            mDeq.pop_back();
            tmp.push_back(node->val);
            // 先右后左加入下层节点
            if (node->right != nullptr)
                mDeq.push_front(node->right);
            if (node->left != nullptr)
                mDeq.push_front(node->left);
        }
        iRes.push_back(tmp);
    }
    return iRes;
}

/**
 * @brief 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

          B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 *
 *
 *
 * @return true
 * @return false
 */
bool isSubStructure(TreeNode *A, TreeNode *B)
{
    return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
}

/**
 * @brief 判断节点值是否一样，一样的话继续递归判断子节点的值是否一样
 * 
 * @param A 
 * @param B 
 * @return true 
 * @return false 
 */
bool recur(TreeNode *A, TreeNode *B)
{
    if (B == nullptr)
        return true;
    if (A == nullptr || A->val != B->val)
        return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
}