#include "../include/leetcode.h"

/**
 * @brief 746. 使用最小花费爬楼梯
 * @see https://leetcode.cn/problems/min-cost-climbing-stairs/
 */
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0; // 默认第一步都是不花费体力的
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        for (int v : dp)
            cout << v << " ";
        return dp[cost.size()];
    }

    // 拓展
    // 旧力扣描述，如果按照 第一步是花费的，最后一步不花费，那么代码是这么写的，提交也可以通过
    int minCostClimbingStairs_2(vector<int> &cost)
    {
        vector<int> dp(cost.size());
        dp[0] = cost[0]; // 第一步有花费
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        for (int v : dp)
            cout << v << " ";
        // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

int main()
{
    Solution sln;
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    auto ans1 = sln.minCostClimbingStairs(cost);
    cout << "\nans1 = " << ans1 << "\n";
    auto ans2 = sln.minCostClimbingStairs_2(cost);
    cout << "\nans2 = " << ans2;

    return 0;
}