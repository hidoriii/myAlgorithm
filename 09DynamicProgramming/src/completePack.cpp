#include "../include/leetcode.h"

void completePack()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bag_size = 4;
    vector<int> dp(bag_size + 1, 0);
    // 先遍历物品，在遍历背包
    for (int i = 0; i < weight.size(); i++) // 遍历物品
    {
        for (int j = weight[i]; j <= bag_size; j++) // 遍历背包容量
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); // 状态转移方程
        }
    }
    cout << dp[bag_size] << endl;
}

void completePack_2()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bag_size = 4;
    vector<int> dp(bag_size + 1, 0);
    // 先遍历背包，在遍历物品
    for (int j = 0; j <= bag_size; j++) // 遍历背包容量
    {
        for (int i = 0; i < weight.size(); i++) // 遍历物品
        {
            if (j >= weight[i]) // 保证物品能放进背包
            {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[bag_size] << endl;
}

void completePack_3()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bag_size = 4;
    vector<vector<int>> dp(weight.size() + 1, vector<int>(bag_size + 1, 0));
    // 先遍历背包，在遍历物品
    for (int i = 1; i <= weight.size(); i++) // 遍历物品
    {
        for (int j = 1; j <= bag_size; j++) // 遍历背包容量
        {
            if (j >= weight[i - 1]) // 保证物品能放进背包
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i - 1]] + value[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[weight.size()][bag_size] << endl;
}

int main()
{
    completePack();
    completePack_2();
    completePack_3();
    return 0;
}