#include <vector>
#include <algorithm>
using std::vector;

/**
 * @brief 47. 全排列 II
 * @see https://leetcode.cn/problems/permutations-ii/
 */
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // used[i - 1] == true   说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false  说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) // 这里换成 used[i-1] == true 也是可以AC的
                continue;
            if (used[i] == false) // 如果被使用过 直接跳过 执行 i++ 进入下一个数字
            {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};