#include "../include/leetcode.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += nums[i];
            if (count > result) // 取区间累计的最大值（相当于不断确定（更新）最大子序终止位置）
            {
                result = count;
            }
            if (count <= 0) // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
            {
                count = 0;
            }
        }
        return result;
    }
};

int main()
{
    Solution sln;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2{1};
    vector<int> nums3{5, 4, -1, 7, 8};
    int ans = sln.maxSubArray(nums);
    cout << ans << endl;
    return 0;
}