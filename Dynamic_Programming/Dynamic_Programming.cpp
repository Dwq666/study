#include "Dynamic_Programming.h"

/**
 * @brief 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下:
 *  F(0) = 0,   F(1) = 1
    F(N) = F(N - 1) + F(N - 2), 其中 N > 1.

    答案需要取模 1e9+7（1000000007),因为int32位取值范围是-2147483648～2147483647，
    1000000007 是最小的十位质数。模1000000007，可以保证值永远在int的范围内，
    int64位的最大值为2^63-1，对于1000000007来说它的平方不会在int64中溢出，
    所以在大数相乘的时候，因为(a∗b)%c=((a%c)∗(b%c))%c，所以相乘时两边都对1000000007取模，
    再保存在int64里面不会溢出

 *
 * @param n
 * @return int
 */
int fib(int n)
{
    int a = 0, b = 1, sum;
    for (int i = 0; i < n; i++)
    {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    return a;
}

/**
 * @brief 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法(跟上一题一样)
 *
 * @param n
 * @return int
 */
int numWays(int n)
{
    int a = 1, b = 1, sum;
    for (int i = 0; i < n; i++)
    {
        sum = (a + b) % 1000000007;
        a = b;
        b = sum;
    }
    return a;
}

/**
 * @brief 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？


 *
 * @param prices
 * @return int
 */
int maxProfit(vector<int> &prices)
{
    int cost = INT_MAX, profit = 0;
    for (auto price : prices)
    {
        //获得最小值
        cost = min(cost, price);
        //利润最大值
        profit = max(profit, price - cost);
    }
    return profit;
}

/**
 * @brief 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 *
 * @param nums
 * @return int
 */
int maxSubArray(vector<int> &nums)
{
    // res存储最大值
    int res = nums.at(0);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums.at(i - 1) > 0)
            nums.at(i) += nums.at(i - 1);
        if (nums.at(i) > res)
            res = nums.at(i);
    }
    return res;
}

/**
 * @brief 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
 * 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？


 *
 * @param grid
 * @return int
 */
int maxValue(vector<vector<int>> &grid)
{
    //取数组行数m，取数组列数n
    int m = grid.size(), n = grid.at(0).size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
                grid.at(i).at(j) += grid.at(i).at(j - 1);
            else if (j == 0)
                grid.at(i).at(j) += grid.at(i - 1).at(j);
            else
                grid.at(i).at(j) += max(grid.at(i - 1).at(j), grid.at(i).at(j - 1));
        }
    }
    return grid.at(m - 1).at(n - 1);
}

/**
 * @brief 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，
 *  1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。
 * 请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法


 *
 * @param num
 * @return int
 */
int translateNum(int num)
{
    //将数组转化字符串
    string s = to_string(num);
    int a = 1, b = 1, len = s.size();
    //从2开始进行循环比对
    for (int i = 2; i <= len; i++)
    {
        //获取两位
        string tmp = s.substr(i - 2, 2);
        int c = tmp.compare("10") >= 0 && tmp.compare("25") <= 0 ? a + b : a;
        b = a;
        a = c;
    }
    return a;
}

/**
 * @brief 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 *
 * @param s
 * @return int
 */
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> dic;
    int res = 0, tmp = 0, len = s.size(), i;
    for (int j = 0; j < len; j++)
    {   
        //判断在哈希表里有找到值
        if (dic.find(s[j]) == dic.end())
            i = -1;
        else
            i = dic.find(s[j])->second;//获取索引i
        dic[s[j]] = j;//更新哈希表
        tmp = tmp < j - i ? tmp + 1 : j - i;
        res = max(res,tmp);
    }
    return res;
}