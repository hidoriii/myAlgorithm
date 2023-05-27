#include <vector>
using std::vector;

/**
 * @brief 78. 子集
 * @see https://leetcode.cn/problems/subsets/submissions/
 *
 * @note 回溯法
 *  本题与之前的不同，本题需要回溯收集每一层递归的结果
 */
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        result.push_back(path);        // 收集子集，要放在终止添加的面，否则会漏掉自己
        if (startIndex == nums.size()) // 终止条件可以不加。因为startIndex == nums.size()，本层for循环本来也结束了，本来我们就要遍历整棵树。
        {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};