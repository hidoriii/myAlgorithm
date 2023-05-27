#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 376. 摆动序列
 * @see https://leetcode.cn/problems/wiggle-subsequence/
 */
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int pre_diff = 0; // 前一对差值
        int cur_diff = 0; // 当前一对差值
        int result = 1;   // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++)
        {
            cur_diff = nums[i + 1] - nums[i];
            if ((pre_diff <= 0 && cur_diff > 0) || (pre_diff >= 0 && cur_diff < 0)) // 出现峰值
            {
                result++;
                pre_diff = cur_diff; // 注意这里，只在摆动变化的时候更新 pre_diff
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums1{1, 7, 4, 5, 6, 8, 3, 10};
    vector<int> nums2{1, 2, 2, 2, 1};
    vector<int> nums3{1, 2, 2, 2, 3, 4};
    Solution sln;
    int ans = sln.wiggleMaxLength(nums1);
    cout << "ans1=" << ans << "\n";
    cout << "=============\n";
    int ans2 = sln.wiggleMaxLength(nums2);
    cout << "ans2=" << ans2 << "\n";
    cout << "=============\n";
    int ans3 = sln.wiggleMaxLength(nums3);
    cout << "ans3=" << ans3 << "\n";

    return 0;
}