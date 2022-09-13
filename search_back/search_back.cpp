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
    if (root == nullptr)
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
    if (root == nullptr)
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
    if (root == nullptr)
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
 *
 *
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

/**
 * @brief 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 *
 * @param root
 * @return TreeNode*
 */

TreeNode *mirrorTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    //先暂存左子节点
    TreeNode *tmp = root->left;
    //对右子节点进行递归，返回的值给左子节点
    root->left = mirrorTree(root->right);
    //对暂存的左子节点递归，返回的值给右子节点
    root->right = mirrorTree(tmp);
    return root;
}

/**
 * @brief  请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 *
 * @param root
 * @return true
 * @return false
 */
bool isSymmetric(TreeNode *root)
{
    //对比根节点的左子节点和右子节点
    return (root == nullptr) || symmetry(root->left, root->right);
}

bool symmetry(TreeNode *L, TreeNode *R)
{
    if (L == nullptr && R == nullptr)
        return true;
    //判断值是否相等
    if (L == nullptr || R == nullptr || L->val != R->val)
        return false;
    // L的左子节点和R的右子节点进行递归、L的右子节点和R的左子节点进行递归
    return symmetry(L->left, R->right) && symmetry(L->right, R->left);
}

/**
 * @brief 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
 *        如果 word 存在于网格中，返回 true ；否则，返回 false 。
 *
 *    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
 *     同一个单元格内的字母不允许被重复使用。
 *
 */

bool exist(vector<vector<char>> &board, string word)
{
    rows = board.size();
    cols = board[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {   
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}
bool dfs(vector<vector<char>> &board, string word, int i, int j, int k)
{   
    //判断值是否相等
    if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k])
        return false;
    //如果是k是字符串最后一位返回true
    if (k == word.size() - 1)
        return true;
    board[i][j] = '\0';
    //对这个数组值进行上下左右的递归扩散
    bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
               dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
    board[i][j] = word[k];
    return res;
}