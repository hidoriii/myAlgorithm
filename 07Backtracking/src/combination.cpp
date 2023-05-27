#include <iostream>
#include <vector>
using std::vector;

/**
 * @author ray
 * @date 2020-07-01 16:00:00
 * @brief 卧槽！小小的AI震撼！
 */

/**
 * @brief 77. 组合
 * @see https://leetcode-cn.com/problems/combinations/
 * @param n 1 <= n <= 20
 * @param k 1 <= k <= n
 * @return 所有可能的 k 个数的组合
 * @note 回溯法
 * @note 1. 递归函数参数：当前处理的节点，当前已经处理的节点个数
 * @note 2. 递归终止条件：当前已经处理的节点个数等于 k
 * @note 3. 递归过程：遍历当前节点的所有子节点，递归处理子节点
 * @note 4. 回溯：撤销当前节点的处理
 * @note 5. 时间复杂度：O(n^k)
 * @note 6. 空间复杂度：O(k)
 * @note 7. 本题中，每个节点的子节点个数都是确定的，因此可以用循环代替递归
 * @note 8. 回溯模板：
 *  void backtracking(参数) {
        if (终止条件) {
            存放结果;
            return;
        }

        for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
            处理节点;
            backtracking(路径，选择列表); // 递归
            回溯，撤销处理结果
        }
    }
 */
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        result.clear(); // 清空上一次的结果（可以不写）
        path.clear();   // 清空上一次的结果
        backtracking(n, k, 1);
        return result;
    }

private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;           // 存放符合条件的单一结果

    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        // for (int i = startIndex; i <= n; i++) // 之前的版本

        /**
         * @brief 剪枝的目的 为了减少不必要的递归
         * @note 1. k - path.size() 表示还需要处理的节点个数
         * @note 2. 剪枝的条件是：列表中剩余元素（n-i） >= 所需要的元素个数 (k - path.size())
         * @note 3. 在集合n中至多要从该起始位置: i <= n - (k - path.size()) + 1 开始遍历
         * @note 4. +1 是因为索引从 1 开始（因为包括起始位置，我们要是一个左闭的集合）
         */
        for (int i = startIndex; i <= (n - (k - path.size()) + 1); i++) // 剪枝（优化的地方）
        {
            path.push_back(i);         // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back();           // 回溯，撤销处理的节点
        }
    }
};

int main()
{
    Solution sln;
    int q;
    std::cin >> q;
    vector<int> vec;
    for (int i = 0, n, k; i < q; i++)
    {
        std::cin >> k >> n;
        auto ans = sln.combine(n, k);
        vec.push_back(ans.size());
    }

    for (auto i : vec)
        std::cout << i << "\n";

    return 0;
}