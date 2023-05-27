#include "../include/leetcode.h"

/**
 * @brief 55. 跳跃游戏
 * @see https://leetcode.cn/problems/jump-game/
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1) // 只有一个元素，就是能达到
            return true;
        int cover = 0;
        for (int i = 0; i <= cover; i++) // 注意这里是小于等于cover
        {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) // 说明可以覆盖到终点了
                return true;
        }
        return false;
    }
};