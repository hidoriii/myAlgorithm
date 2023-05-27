#include "../include/leetcode.h"

/**
 * @brief 494. 目标和
 * @see https://leetcode-cn.com/problems/target-sum/
 */
class Solution
{
public:
    // v1: 动态规划
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || (sum + target) % 2 == 1) // 此时没有方案
        {
            return 0;
        }
        int bag_size = (sum + target) / 2;
        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bag_size; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag_size];
    }

    // v2: 回溯
    int findTargetSumWays_2(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || (sum + target) % 2 == 1) // 此时没有方案
        {
            return 0;
        }
        int bag_size = (sum + target) / 2; // 转变为组合总和问题， bag_size 就是要求的和
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, bag_size, 0);
        return result.size();
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int sum, int target, int startIndex)
    {
        if (sum == target)
        {
            result.push_back(path);
            // return; // 这里不能return，因为还有可能有别的分支满足条件
        }
        for (int i = startIndex; i < nums.size() && sum + nums[i] <= target; i++)
        {
            sum += nums[i];
            path.push_back(nums[i]);
            backtracking(nums, sum, target, i + 1);
            path.pop_back();
            sum -= nums[i];
        }
    }
};

int main()
{
    vector<int> nums{0, 0, 0, 0, 0, 0};
    int target = 0;
    Solution sln;
    int ans = sln.findTargetSumWays_2(nums, target);
    cout << ans << endl;

    return 0;
}