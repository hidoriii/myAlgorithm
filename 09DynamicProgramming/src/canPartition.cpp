#include "../include/leetcode.h"

/**
 * @brief 416. 分割等和子集
 * @see https://leetcode.cn/problems/partition-equal-subset-sum/
 * 
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，
 * 使得两个子集的元素和相等。
 */
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        // vector<int> dp(10001, 0);

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) // 奇数直接返回false
            return false;

        int target = sum / 2; // 目标值等于sum的一半

        vector<int> dp(target + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--) // 每一个元素一定是不可重复放入，所以从大到小遍历
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[target] == target)
            return true;
        return false;
    }
};