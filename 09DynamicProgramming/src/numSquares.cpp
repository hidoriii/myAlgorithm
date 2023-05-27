#include "../include/leetcode.h"

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) // 遍历物品
        {
            for (int j = i * i; j <= n; j++) // 遍历背包
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
    // v2
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int j = 0; j <= n; j++) // 遍历背包
        {
            for (int i = 1; i * i <= j; i++) // 遍历物品
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};