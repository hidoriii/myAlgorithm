#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 455. 分发饼干
 * @see https://leetcode.cn/problems/assign-cookies/submissions/
 */
class Solution
{
public:
    // 时间复杂度：O(nlogn)
    // 空间复杂度：O(1)
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) // 遍历胃口
        {
            if (index >= 0 && s[index] >= g[i]) // 遍历饼干
            {
                result++;
                index--;
            }
        }
        return result;
    }

    int findContentChildren_2(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.size(); i++) // 对于每个饼干
        {
            if (index < g.size() && g[index] <= s[i]) // 如果这块饼干满足最低限制的胃口
            {
                index++;
            }
        }
        return index;
    }
};