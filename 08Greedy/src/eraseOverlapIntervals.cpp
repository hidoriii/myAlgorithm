#include "../include/leetcode.h"

/**
 * @brief 435. 无重叠区间
 * @see https://leetcode.cn/problems/non-overlapping-intervals/
 */
class Solution
{
public:
    // v1: 按照区间左边界排序
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        int count = 0;             // 注意这里从0开始，因为是记录重叠区间
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= end) // 无重叠的情况
            {
                end = intervals[i][1]; // 更新分隔点 end的值
            }
            else // 重叠情况
            {
                end = min(end, intervals[i][1]);
                count++;
            }
        }
        return count;
    }

    // v2: 按照区间右边界排序
    int eraseOverlapIntervals_2(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] > b[0]; });
        int count = 1;             // 记录非交叉区间的个数
        int end = intervals[0][1]; // 记录区间分割点
        for (int i = 1; i < intervals.size(); i++)
        {
            if (end <= intervals[i][0])
            {
                end = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int count = sln.eraseOverlapIntervals(intervals);
    cout << "count=" << count << "\n";
    return 0;
}