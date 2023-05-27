#include "../include/leetcode.h"

class Solution
{
public:
    // v1
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] != INT_MAX) // 如果dp[j - coins[i]]是初始值则跳过
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX) // 如果dp[amount]是初始值则说明没有找到
            return -1;
        return dp[amount];
    }
    // v2
    int coinChange_2(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int j = 0; j <= amount; j++)
        {
            for (int i = 0; i < coins.size(); i++)
            {
                if (j - coins[i] >= 0 && dp[j - coins[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};