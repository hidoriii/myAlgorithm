#include "../include/leetcode.h"

/**
 * @brief 509. 斐波那契数
 * @see https://leetcode.cn/problems/fibonacci-number/
 */
class Solution
{
public:
    // v1
    int fib(int n)
    {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1);
        // dp[i]的定义为：第i个数的斐波那契数值是dp[i]
        dp[0] = 0;
        dp[1] = 1;
        // 从递归公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出
        // dp[i]是依赖 dp[i - 1] 和 dp[i - 2]，那么遍历的顺序一定是从前到后遍历的
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2]; // 状态转移方程
        }
        return dp[n];
    }

    // v2: 当然可以发现，我们只需要维护两个数值就可以了，不需要记录整个序列。
    int fib_2(int n)
    {
        if (n <= 1)
            return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }

    // v3: 递归
    int fib(int n)
    {
        if (n < 2)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};