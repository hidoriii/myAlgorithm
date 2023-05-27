#include "../include/leetcode.h"

/**
 * @brief 134. 加油站
 * @see https://leetcode.cn/problems/gas-station/submissions/
 */
class Solution
{
public:
    // 贪心算法（方法一）
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int cur_sum = 0;
        int min = INT_MAX; // 从起点出发，油箱里的油量最小值
        for (int i = 0; i < gas.size(); i++)
        {
            int rest = gas[i] - cost[i];
            cur_sum += rest;
            if (cur_sum < min)
            {
                min = cur_sum;
            }
        }
        if (cur_sum < 0) // 情况一：如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的
            return -1;
        if (min >= 0) // 情况二：如果累加没有出现负数，说明从0出发，油就没有断过，那么0就是起点
            return 0;
        // 情况三：如果累加的最小值是负数，汽车就要从非0节点出发，从后向前，看哪个节点能把这个负数填平，能把这个负数填平的节点就是出发节点。
        for (int i = gas.size() - 1; i >= 0; i--)
        {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0)
            {
                return i;
            }
        }
        return -1;
    }

    // 贪心算法（方法二）
    int canCompleteCircuit_2(vector<int> &gas, vector<int> &cost)
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) // 当前累加 rest[i]和 curSum一旦小于0
            {
                start = i + 1; // 起始位置更新为i+1
                curSum = 0;    // curSum从 0开始
            }
        }
        if (totalSum < 0) // 说明怎么走都不可能跑一圈了
        {
            return -1;
        }
        return start;
    }

    // 暴力解法
    int canCompleteCircuit_3(vector<int> &gas, vector<int> &cost)
    {
        for (int i = 0; i < cost.size(); i++)
        {
            int rest = gas[i] - cost[i]; // 记录剩余油量
            int index = (i + 1) % cost.size();
            while (rest > 0 && index != i)
            { // 模拟以i为起点行驶一圈（如果有rest==0，那么答案就不唯一了）
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            // 如果以i为起点跑一圈，剩余油量>=0，返回该起始位置
            if (rest >= 0 && index == i)
                return i;
        }
        return -1;
    }
};