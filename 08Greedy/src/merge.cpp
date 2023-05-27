#include "../include/leetcode.h"

/**
 * @brief 56. 合并区间
 * @see https://leetcode.cn/problems/merge-intervals/
 */
class Solution
{
public:
    // v1: by myself
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return {{}};
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> result;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > intervals[i - 1][1])
            {
                result.push_back(vector<int>{start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
                end = intervals[i][1];
            }
        }
        result.push_back(vector<int>{start, end});
        return result;
    }

    // v2
    vector<vector<int>> merge_2(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0)
            return result; // 区间集合为空直接返回
        // 排序的参数使用了lambda表达式
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        // 第一个区间就可以放进结果集里，后面如果重叠，在result上直接合并
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (result.back()[1] >= intervals[i][0]) // 发现重叠区间
            {
                // 合并区间，只更新右边界就好，因为result.back()的左边界一定是最小值，因为我们按照左边界排序的
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else // 区间不重叠
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};