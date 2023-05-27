#include "../include/leetcode.h"

/**
 * @brief 70. 爬楼梯
 * @see https://leetcode.cn/problems/climbing-stairs/
 */
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1) // 因为下面直接对dp[2]操作了，防止空指针
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) // 注意i是从3开始的
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // 拓展
    // 这道题目还可以继续深化，就是一步一个台阶，两个台阶，三个台阶，直到 m个台阶，有多少种方法爬到n阶楼顶。
    int climbMStairs(int n, int m)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) // 把m换成2，就可以AC爬楼梯这道题
            {
                if (i - j >= 0) // 防止溢出
                {
                    dp[i] += dp[i - j];
                }
            }
        }
        return dp[n];
    }
};