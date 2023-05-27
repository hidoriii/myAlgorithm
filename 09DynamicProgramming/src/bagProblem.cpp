#include "../include/leetcode.h"

void findWhat(const vector<vector<int>> &dp, const vector<int> &weight, const vector<int> &value, int i, int j, vector<int> &res);

// 0-1背包问题
void bagProblem()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // dp[i][j]表示前i个物品放入容量为j的背包中的最大价值
    vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));

    // 初始化第一行
    for (int j = weight[0]; j <= bagWeight; j++)
    {
        dp[0][j] = value[0];
    }

    for (int i = 1; i < weight.size(); i++) // 遍历物品
    {
        for (int j = 1; j <= bagWeight; j++) // 遍历背包容量
        {
            if (j < weight[i]) // 背包容量小于物品重量
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[weight.size() - 1][bagWeight] << endl; // 背包重bagWeight的最大价值

    // 找到放入背包的物品
    vector<int> res;
    findWhat(dp, weight, value, weight.size() - 1, bagWeight, res);
    for (auto i : res)
    {
        cout << i << " ";
    }
}

// 找到放入背包的物品
void findWhat(const vector<vector<int>> &dp, const vector<int> &weight, const vector<int> &value, int i, int j, vector<int> &res)
{
    // 递归终止条件
    if (i == 0)
    {
        if (dp[i][j] == value[i]) // 放入了第1个物品
        {
            res.push_back(i); // 记录第1个物品
        }
        return;
    }
    if (dp[i][j] == dp[i - 1][j]) // 没有放入第i个物品
    {
        findWhat(dp, weight, value, i - 1, j, res);
    }
    else // 放入了第i个物品
    {
        res.push_back(i); // 记录第i个物品
        findWhat(dp, weight, value, i - 1, j - weight[i], res);
    }
}

// 一维数组优化
void bagProblem_2()
{
    vector<int> weight = {1, 2, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    // dp[i][j]表示前i个物品放入容量为j的背包中的最大价值
    vector<int> dp(bagWeight + 1, 0);

    // 初始化第一行
    for (int j = weight[0]; j <= bagWeight; j++)
    {
        dp[j] = value[0];
    }

    for (int i = 1; i < weight.size(); i++) // 遍历物品
    {
        for (int j = bagWeight; j >= weight[i]; j--) // 倒叙遍历背包容量
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << dp[j] << " ";
        }
    }
    // 注意：
    // 倒叙遍历背包容量 处理 0-1背包问题
    // 正序遍历背包容量 处理 完全背包问题

    cout << dp[bagWeight] << endl; // 背包重bagWeight的最大价值
}

int main()
{
    // bagProblem();
    bagProblem_2();

    return 0;
}
