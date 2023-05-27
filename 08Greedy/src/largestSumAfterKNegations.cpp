#include "../include/leetcode.h"

/**
 * @brief 1005. K次取反后最大化的数组和
 * @see https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
 */
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), [](int a, int b)
             { return abs(a) > abs(b); });    // 将数组按照绝对值大小从大到小排序，注意要按照绝对值的大小
        for (int i = 0; i < nums.size(); i++) // 从前向后遍历，遇到负数将其变为正数，同时k--
        {
            if (nums[i] < 0 && k > 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) // 如果 k 还大于0 且 k 为奇数，那么反复转变 绝对值 最小的元素，将 k 用完
            nums[nums.size() - 1] *= -1;
        int result = 0;
        for (int num : nums) // 求和
            result += num;
        return result;
    }
};

int main()
{
    Solution sln;
    vector<int> nums{4, 2, 3};
    int ans = sln.largestSumAfterKNegations(nums, 1);
    cout << ans << "\n";
    return 0;
}