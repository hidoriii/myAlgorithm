#include "../include/leetcode.h"

/**
 * @brief 763. 划分字母区间
 * @see https://leetcode.cn/problems/partition-labels/
 */
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int hash[27] = {0};                // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < s.size(); i++) // 统计每一个字符最后出现的位置
        {
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']);
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};