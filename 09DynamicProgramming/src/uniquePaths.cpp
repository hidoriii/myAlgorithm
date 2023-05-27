#include "../include/leetcode.h"

/**
 * @brief 62. 不同路径
 * @see https://leetcode-cn.com/problems/unique-paths/
 *
 * @param m 行数
 * @param n 列数
 * @return int 路径数
 */
class Solution
{
public:
    // v1 动态规划
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        // 从左到右遍历
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    // v2 深搜
    int uniquePaths2(int m, int n)
    {
        int res = 0;
        dfs(m, n, 0, 0, res);
        return res;
    }

    // v3 数论: C(m+n-2, n-1) 或 C(m+n-2, m-1)
    int uniquePaths3(int m, int n)
    {
        // long long ans = 1;
        // for (int x = n, y = 1; y < m; ++x, ++y)
        // {
        //     ans = ans * x / y;
        // }
        // return ans;

        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2;
        while (count--)
        {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0)
            {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }

private:
    void dfs(int m, int n, int i, int j, int &res)
    {
        if (i == m - 1 && j == n - 1)
        {
            res++;
            return;
        }
        if (i < m - 1)
            dfs(m, n, i + 1, j, res);
        if (j < n - 1)
            dfs(m, n, i, j + 1, res);
    }
};