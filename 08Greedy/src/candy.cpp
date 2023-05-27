#include "../include/leetcode.h"

/**
 * @brief 135. 分发糖果
 * @see https://leetcode.cn/problems/candy/
 */
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) // 从前向后
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) // 从后向前
        {
            if (ratings[i + 1] < ratings[i])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        int result = 0;
        for (int candy : candies)
            result += candy;
        return result;
    }
};