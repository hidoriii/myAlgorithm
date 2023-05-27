#include "../include/leetcode.h"

/**
 * @brief 63. 不同路径 II
 * @see https://leetcode-cn.com/problems/unique-paths-ii/
 *
 * @param obstacleGrid
 * @return int
 */
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();    // 行数
        int n = obstacleGrid[0].size(); // 列数
        // 如果在起点或终点出现了障碍，直接返回0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
            dp[0][j] = 1;
        // 从左到右遍历
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1]; // 返回终点的路径数
    }
};