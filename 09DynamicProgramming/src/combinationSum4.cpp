#include "../include/leetcode.h"

/**
 * @brief 377. 组合总和 Ⅳ
 * @see https://leetcode-cn.com/problems/combination-sum-iv/
 */
class Solution
{
public:
    // 动态规划
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]]) // 防止溢出
                {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }

    // 回溯算法 （但 LeetCode上超时了）
    int combinationSum4_2(vector<int> &nums, int target)
    {
        int ans = 0;
        backtracking(nums, target, ans);
        return ans;
    }

private:
    void backtracking(vector<int> &nums, int target, int &ans)
    {
        if (target == 0) // 找到一个组合
        {
            ans++;
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (target >= nums[i]) // 防止溢出
            {
                backtracking(nums, target - nums[i], ans);
            }
        }
    }
};