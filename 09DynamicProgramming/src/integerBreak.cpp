#include "../include/leetcode.h"

/**
 * @brief 343. 整数拆分
 * @see https://leetcode-cn.com/problems/integer-break/
 *
 * @param n
 * @return int
 */
class Solution
{
public:
    // v1: 动态规划
    int integerBreak(int n)
    {
        vector<int> dp(n + 1); // 分拆数字i，可以得到的最大乘积为dp[i]
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            // 拆分一个数n 使之乘积最大，那么一定是拆分成 m个近似相同的子数相乘才是最大的
            // 所以 j 遍历，只需要遍历到 n/2 就可以，后面就没有必要遍历了，一定不是最大值。
            for (int j = 1; j <= i / 2; j++)
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }

    // v2: 贪心算法
    int integerBreak_2(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        int result = 1;
        while (n > 4)
        {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};