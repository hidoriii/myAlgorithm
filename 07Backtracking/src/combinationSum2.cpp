#include <vector>
#include <algorithm>
using std::vector;

/**
 * @brief 40. 组合总和 II
 * @see https://leetcode-cn.com/problems/combination-sum-ii/
 *
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target
 * 找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
 * 你可以按 任意顺序 返回这些组合。
 * candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
 */
namespace CombinationSum2
{
    class Solution
    {
    public:
        vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
        {
            std::sort(candidates.begin(), candidates.end());
            backtracking(candidates, target, 0);
            return result;
        }

    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(vector<int> &candidates, int target, int startIndex)
        {
            if (target == 0)
            {
                result.push_back(path);
                return;
            }
            if (target < 0)
            {
                return;
            }

            for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++)
            {
                target -= candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates, target, i + 1);
                target += candidates[i];
                path.pop_back();
            }
        }
    };
}