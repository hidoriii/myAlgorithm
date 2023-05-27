#include <vector>
#include <unordered_set>
#include <algorithm>
using std::unordered_set;
using std::vector;

/**
 * @brief 491. 递增子序列
 * @see https://leetcode-cn.com/problems/increasing-subsequences/
 *
 * @note 回溯法
 * 本题与之前的不同，本题需要回溯收集每一层递归的结果
 * 本题与之前的不同，本题需要去重
 */
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        result.clear();
        path.clear();

        // version 1: 使用set来对本层元素进行去重
        // backtracking(nums, 0);

        // version 2: 使用数组来对本层元素进行去重（效率更高）
        backtracking_2(nums, 0);

        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        if (path.size() >= 2)
        {
            result.push_back(path);
            // 注意这里不要加 return，因为要取树上的所有节点
        }
        unordered_set<int> uset; // 使用set来对本层元素进行去重
        // unordered_set<int> uset; 是记录本层元素是否重复使用，新的一层uset都会重新定义（清空），所以要知道uset只负责本层！
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) // 如果当前元素比path的最后一个元素小，就跳过
                || uset.find(nums[i]) != uset.end())     // 如果当前元素在本层已经用过了，也跳过
            {
                continue;
            }
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

private:
    // 注意题目中说了，数值范围[-100,100]，所以完全可以用数组来做哈希。效率会明显提高！
    void backtracking_2(vector<int> &nums, int startIndex)
    {
        if (path.size() >= 2)
        {
            result.push_back(path);
        }
        bool used[201] = {false}; // 用来记录本层元素是否重复使用
        for (int i = startIndex; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) // 如果当前元素比path的最后一个元素小，就跳过
                || used[nums[i] + 100] == true)          // 如果当前元素在本层已经用过了，也跳过
            {
                continue;
            }
            used[nums[i] + 100] = true; // 记录这个元素在本层用过了，本层后面不能再用了
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};