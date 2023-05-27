#include "../include/leetcode.h"

/**
 * @brief 474. 一和零
 * @see https://leetcode-cn.com/problems/ones-and-zeroes/
 */
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string s : strs) // 遍历物品
        {
            int x = count(s.begin(), s.end(), '0'); // 统计0的个数
            int y = s.size() - x;                   // 统计1的个数
            for (int i = m; i >= x; i--)            // 遍历背包容量（两个for可以颠倒）
            {
                for (int j = n; j >= y; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1); // 状态转移方程
                }
            }
        }
        return dp[m][n];
    }
};