#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

/**
 * @brief 39. 组合总和
 * @see https://leetcode-cn.com/problems/combination-sum/
 *
 * @note 本题与 40. 组合总和 II 相同，只是本题中的每个数字可以无限制重复被选取。
 */
namespace CombinationSum
{
    class Solution
    {
    public:
        vector<vector<int>> combinationSum(vector<int> &candidates, int target)
        {
            sort(candidates.begin(), candidates.end()); // 本题需要去重，因此要先排序
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

            // for (int i = startIndex; i < candidates.size(); i++)
            // 剪枝优化: 如果 target - candidates[i] >= 0 就终止遍历
            for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++)
            {
                if (i > startIndex && candidates[i] == candidates[i - 1]) // 去重操作
                    continue;                                             // 同一层级上，如果前后两个数相同，就跳过后面的数
                target -= candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates, target, i); // 不用i+1，表示可以重复读取当前的数
                target += candidates[i];
                path.pop_back();
            }
        }
    };
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto result = CombinationSum::Solution().combinationSum(candidates, target);
    // print
    for (auto &v : result)
    {
        for (auto &i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

    return 0;
}