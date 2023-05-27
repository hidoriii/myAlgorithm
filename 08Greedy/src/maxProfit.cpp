#include "../include/leetcode.h"

/**
 * @brief 122. 买卖股票的最佳时机II
 * @see https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            result += max(prices[i] - prices[i - 1], 0); // 贪心求取每天的正利润
        }
        return result;
    }
};