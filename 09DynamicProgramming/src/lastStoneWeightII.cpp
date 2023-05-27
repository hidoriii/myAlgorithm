#include "../include/leetcode.h"

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // 在计算target的时候，target = sum / 2 因为是向下取整，所以 sum - dp[target] 一定是大于等于 dp[target] 的
        // 那么相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]
        return (sum - dp[target]) - dp[target];
    }
};