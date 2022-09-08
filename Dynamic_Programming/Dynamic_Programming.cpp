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