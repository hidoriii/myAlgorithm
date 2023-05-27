#include <vector>
using std::vector;

namespace CombinationSum3
{
    /**
     * @brief 216. 组合总和III
     * @see https://leetcode-cn.com/problems/combination-sum-iii/
     *
     * 找出所有相加之和为 n 的 k 个数的组合。
     * 组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
     *
     * @note 回溯法
     */
    class Solution
    {
    public:
        vector<vector<int>> combinationSum3(int k, int n)
        {
            backtracking(n, k, 1);
            return result;
        }

    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(int targetSum, int k, int startIndex)
        {
            if (path.size() == k)
            {
                if (targetSum == 0)
                    result.push_back(path);
                return; // 如果path.size() == k 但 targetSum != 0 直接返回
            }

            // for (int i = startIndex; i <= 9; i++)
            for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) // 这里也可以剪枝
            {
                targetSum -= i;
                path.push_back(i);
                // 剪枝操作
                if (targetSum < 0) // 如果 targetSum已经小于0，那么就没有继续往下遍历的必要了，直接return
                {
                    targetSum += i;  // 剪枝之前先把回溯做了
                    path.pop_back(); // 回溯
                    return;
                }
                backtracking(targetSum, k, i + 1);
                targetSum += i;  // 回溯
                path.pop_back(); // 回溯
            }
        }
    };
}