#include "../include/leetcode.h"

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        // 如果先遍历物品，再遍历背包，那么就是求组合数（即本题要求的）
        // 如果先遍历背包，再遍历物品，那么就是求排列数（也可以用回溯算法求排列数）
        for (int i = 0; i < coins.size(); i++) // 先遍历物品
        {
            for (int j = coins[i]; j <= amount; j++) // 再遍历背包
            {
                dp[j] += dp[j - coins[i]];
                // cout << "dp[" << j << "] = " << dp[j] << " ";
            }
            // cout << endl;
        }
        return dp[amount];
    }
};

int main()
{
    Solution sln;
    vector<int> coins = {1, 2, 5};
    auto ans = sln.change(5, coins);
    cout << ans << endl;
    return 0;
}