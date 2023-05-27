#include "../include/leetcode.h"

void multiPack()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    vector<int> nums = {2, 3, 1};
    int bagWeight = 10;
    for (int i = 0; i < nums.size(); i++) // 展开物品
    {
        while (nums[i] > 1) // nums[i]保留到1，把其他物品都展开（二进制优化）
        {
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weight.size(); i++) // 遍历物品
    {
        for (int j = bagWeight; j >= weight[i]; j--) // 遍历背包容量
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
        // 打印dp数组
        for (int j = 0; j <= bagWeight; j++)
        {
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    cout << dp[bagWeight] << endl;
}

void multiPack_2()
{
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    vector<int> nums = {2, 3, 1};
    int bagWeight = 10;
    vector<int> dp(bagWeight + 1, 0);

    for (int i = 0; i < weight.size(); i++) // 遍历物品
    {
        for (int j = bagWeight; j >= weight[i]; j--) // 遍历背包容量
        {
            // 以上为01背包，然后加一个遍历个数
            for (int k = 1; k <= nums[i] && (j - k * weight[i]) >= 0; k++) // 遍历个数
            {
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
            }
        }
        // 打印一下dp数组
        for (int j = 0; j <= bagWeight; j++)
        {
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    cout << dp[bagWeight] << endl;
}

int main()
{
    multiPack();
    multiPack_2();

    return 0;
}