#include "Double_Pointer.h"

/**
 * @brief 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
          返回删除后的链表的头节点。
 *
 * @param head
 * @param val
 * @return ListNode*
 */
ListNode *deleteNode(ListNode *head, int val)
{
    //如果val是首节点head的val,直接返回head的下个节点
    if (head->val == val)
        return head->next;
    ListNode *pre = head, *cur = head->next;
    while (cur != nullptr && cur->val != val)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur != nullptr)
        pre->next = cur->next; //删除掉cur节点
    return head;
}

/**
 * @brief 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，
 *       本题从1开始计数，即链表的尾节点是倒数第1个节点
 *       例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。
 *      这个链表的倒数第 3 个节点是值为 4 的节点。
 *
 * @param head
 * @param k
 * @return ListNode*
 */
ListNode *getKthFromEnd(ListNode *head, int k)
{
    ListNode *former = head, *latter = head;
    // former指针先走k步，让former与latter想差k
    for (int i = 0; i < k; i++)
    {
        if (former == nullptr)
            return nullptr;
        former = former->next;
    }
    // latter和former每循环一次各走一步，当former=null跳出，latter就是链表倒数k个的节点
    while (former != nullptr)
    {
        latter = latter->next;
        former = former->next;
    }
    return latter;
}

/**
 * @brief 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 *
 * @param l1
 * @param l2
 * @return ListNode*
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    //初始化伪头节点dum，节点cur指向dum
    ListNode *dum = new ListNode(0);
    ListNode *cur = dum;
    //
    while (l1 != nullptr && l2 != nullptr)
    {
        // l1值大于等于l2的值，cur指向l2
        if (l1->val >= l2->val)
        {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        else //否则cur指向l1
        {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
    }

    //如果l1不为空，则最后cur指向l1，否则指向l2（因为跳出上面循环需要l1为空或l2为空，所以l1和l2必有一个为空）
    if (l1 != nullptr)
        cur->next = l1;
    else
        cur->next = l2;

    return dum->next;
}

/**
 * @brief 输入两个链表，找出它们的第一个公共节点。
 *
 * @param headA
 * @param headB
 * @return ListNode*
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *A = headA, *B = headB;
    while (A != B)
    {
        //指针 A 先遍历完链表 headA ，再开始遍历链表 headB
        A = A != nullptr ? A->next : headB;
        //指针 B 先遍历完链表 headB ，再开始遍历链表 headA
        B = B != nullptr ? B->next : headA;
    }
    return A;
}

/**
 * @brief 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分
 *
 * @param nums
 * @return vector<int>
 */
vector<int> exchange(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        //从左向右循环找到偶数
        while (i < j && (nums.at(i) % 2) == 1)
            i++;
        //从右向左循环找到奇数
        while (i < j && (nums.at(j) % 2) == 0)
            j--;
        swap(nums.at(i), nums.at(j));
    }
    return nums;
}

/**
 * @brief 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
 *
 * @param nums
 * @param target
 * @return vector<int>
 */
vector<int> twoSum(vector<int> &nums, int target)
{
    int i = 0, j = nums.size() - 1;
    vector<int> ivec;
    while (i < j)
    {
        //获取两数和
        int s = nums.at(i) + nums.at(j);
        //大于target
        if (s > target)
            j--;
        //小于target
        else if (s < target)
            i++;
        else
        {
            ivec.push_back(nums[i]);
            ivec.push_back(nums[j]);
            return ivec;
        }
    }
    return {};
}

/**
 * @brief 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
 *       例如输入字符串"I am a student. "，则输出"student. a am I"。

 *
 * @param s
 * @return string
 */
string reverseWords(string s)
{
    int left = 0, right = s.size() - 1;
    //删除前后空白符
    while (left <= right && s[left] == ' ')
        left++;
    while (left <= right && s[right] == ' ')
        right--;

    deque<string> sdeq;
    string word;
    while (left <= right)
    {
        char c = s[left];
        if (c != ' ')
            word += c;
        else if (word.size() && c == ' ')
        {
            //加入队列头部
            sdeq.push_front(move(word));
            word = "";
        }
        left++;
    }

    sdeq.push_front(move(word));

    string res;
    while (!sdeq.empty())
    {
        //获得队列头部
        res += sdeq.front();
        //头部出队
        sdeq.pop_front();
        if (!sdeq.empty())
            res += ' ';
    }
    return res;
}