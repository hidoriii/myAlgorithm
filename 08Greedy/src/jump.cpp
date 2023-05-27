#include "../include/leetcode.h"

/**
 * @brief 45. 跳跃游戏II
 * @see https://leetcode.cn/problems/jump-game-ii/
 */
class Solution
{
public:
    // version 1
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int result = 0;        // 记录走的最大步数
        int cur_distance = 0;  // 当前覆盖最远距离下标
        int next_distance = 0; // 下一步覆盖最远距离下标
        for (int i = 0; i < nums.size(); i++)
        {
            next_distance = max(nums[i] + i, next_distance); // 更新下一步覆盖最远距离下标
            if (i == cur_distance)                           // 遇到当前覆盖最远距离下标
            {
                if (cur_distance < nums.size() - 1) // 如果当前覆盖最远距离下标不是终点
                {
                    result++;                             // 需要走下一步
                    cur_distance = next_distance;         // 更新当前覆盖最远距离下标（相当于加油了）
                    if (next_distance >= nums.size() - 1) // 下一步的覆盖范围已经可以达到终点，结束循环
                    {
                        break;
                    }
                }
                else
                {
                    break; // 当前覆盖最远距到达集合终点，不用做 result++ 操作了，直接结束
                }
            }
        }
        return result;
    }
    // version 2
    int jump_2(vector<int> &nums)
    {
        int curDistance = 0;  // 当前覆盖的最远距离下标
        int ans = 0;          // 记录走的最大步数
        int nextDistance = 0; // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size() - 1; i++)
        {                                                  // 注意这里是小于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
            if (i == curDistance)
            {                               // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance; // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};