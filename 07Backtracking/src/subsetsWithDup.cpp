#include <vector>
#include <algorithm>
using std::vector;

/**
 * @brief 90. 子集 II
 * @see https://leetcode-cn.com/problems/subsets-ii/
 *
 * @note 回溯法
 * 本题与之前的不同，本题需要回溯收集每一层递归的结果
 * 本题与之前的不同，本题需要去重
 */
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序，方便去重
        backtracking(nums, 0);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1]) // 去重
            {
                continue; // 本层递归中，如果有重复的元素，就跳过
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};