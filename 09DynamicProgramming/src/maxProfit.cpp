#include "../include/leetcode.h"

class Solution
{
public:
    /**
     * @brief 121. 买卖股票的最佳时机
     * @see https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
     * @note v1
     * @note T(n) = O(n)，S(n) = O(n)
     *
     * @param prices
     * @return int
     */
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        // dp[i][0] 表示第i天持有股票的最大收益
        // dp[i][1] 表示第i天不持有股票的最大收益
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0]; // 第一天买入股票
        dp[0][1] = 0;          // 第一天不买入股票
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);               // 寻找以最低价格买入股票的那一天
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // 寻找以最高价格卖出股票的那一天
        }
        return dp[n - 1][1];
    }

    // v2: 动规 + 滚动数组  T(n) = O(n)，S(n) = O(1)
    int maxProfit_2(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2, 0)); // 注意这里只开辟了一个2 * 2大小的二维数组
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }
        return dp[(n - 1) % 2][1];
    }

#define MAX_PROFIT_II
#ifdef MAX_PROFIT_II
    /**
     * @brief 122. 买卖股票的最佳时机 II
     * @see https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
     * @note 动态规划
     *
     * @param prices
     * @return int
     */
    int maxProfit_II(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); // 买入股票//!注意这里是和 121.买卖股票的最佳时机 唯一不同的地方
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // 卖出股票
        }
        return dp[n - 1][1];
    }
    // v2: 动规 + 滚动数组
    int maxProfit_II_2(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2)); // 注意这里只开辟了一个2 * 2大小的二维数组
        dp[0][0] -= prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }
        return dp[(n - 1) % 2][1];
    }
#endif // MAX_PROFIT_II

#define MAX_PROFIT_III
#ifdef MAX_PROFIT_III
    /**
     * @brief 123. 买卖股票的最佳时机 III
     * @see https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
     *
     * @param prices
     * @return int
     */
    int maxProfit_III(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0][0] = 0;          // 没有操作（其实我们也可以不设置这个状态）
        dp[0][1] -= prices[0]; // 第一次买入股票（第一天第一次买入）
        dp[0][2] = 0;          // 第一次卖出股票（第一次卖出）
        dp[0][3] -= prices[0]; // 第二次买入股票（第一天第二次买入）
        dp[0][4] = 0;          // 第二次卖出股票（第二次卖出）
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[n - 1][4];
    }
#endif

#define MAX_PROFIT_IV
#ifdef MAX_PROFIT_IV
    /**
     * @brief 188. 买卖股票的最佳时机 IV
     * @see https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
     * @note 动态规划
     *
     * @param k 交易次数
     * @param prices
     * @return int
     */
    int maxProfit_IV(int k, vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        // 初始化
        for (int j = 1; j < 2 * k; j += 2)
        {
            dp[0][j] = -prices[0];
        }
        // 状态转移
        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 0; j < 2 * k - 1; j += 2) // 除0外，奇数列表示买入股票，偶数列表示卖出股票
            {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);     // 买入股票
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]); // 卖出股票
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
#endif // MAX_PROFIT_IV

#define MAX_PROFIT_COOLDOWN
#ifdef MAX_PROFIT_COOLDOWN
    /**
     * @brief 309. 最佳买卖股票时机含冷冻期
     * @see https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
     * @note 动态规划
     * @note 冷冻期：卖出股票后的第二天不能买入股票
     *
     * @param prices
     * @return int
     */
    int maxProfitWithCoolDown(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] -= prices[0]; // 持股票
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i])); // 买入股票状态
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);                                            // 保持卖出股票状态
            dp[i][2] = dp[i - 1][0] + prices[i];                                                   // 今天就卖出股票状态
            dp[i][3] = dp[i - 1][2];                                                               // 冷冻期状态
        }
        return max(dp[n - 1][3], max(dp[n - 1][1], dp[n - 1][2]));
    }
#endif // MAX_PROFIT_COOLDOWN

#define MAX_PROFIT_WITH_FEE
#ifdef MAX_PROFIT_WITH_FEE
    /**
     * @brief 714. 买卖股票的最佳时机含手续费
     * @see https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
     * @note 动态规划
     *
     * @param prices
     * @param fee 手续费
     * @return int
     */
    int maxProfitWithFee(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);       // 买入股票状态
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee); // 卖出股票状态
        }
        return dp[n - 1][1];
    }
#endif // MAX_PROFIT_WITH_FEE
};