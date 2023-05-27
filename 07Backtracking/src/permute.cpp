#include <vector>
#include <algorithm>
using std::vector;

/**
 * @brief 46. 全排列
 * @see https://leetcode.cn/problems/permutations/submissions/
 *
 * @note 回溯法
 */
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size()) // 此时说明找到了一组
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true) // path里已经收录的元素，直接跳过
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
};