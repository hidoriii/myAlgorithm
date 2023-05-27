#include "../include/leetcode.h"

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);       // dp[i]表示i个节点的二叉搜索树的个数
        dp[0] = 1;                   // 0个节点的二叉搜索树的个数为1
        for (int i = 1; i <= n; i++) // 从1开始遍历
        {
            for (int j = 1; j <= i; j++) // 以j为根节点
            {
                dp[i] += dp[j - 1] * dp[i - j]; // 状态转移方程
                // cout << "dp[" << i << "] = " << dp[i] << " ";
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    auto ans = s.numTrees(4);
    cout << "\nans = " << ans << endl;
    return 0;
}