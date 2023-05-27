#include "../include/leetcode.h"

struct TreeNode;

class Solution
{
public:
    /**
     * @brief 198. 打家劫舍
     * @see https://leetcode-cn.com/problems/house-robber/
     *
     * @param nums
     * @return int
     */
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); // 这里要注意，dp[1]不一定是nums[1]，因为可能nums[0]大
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }

    /**
     * @brief 213. 打家劫舍 II
     * @see https://leetcode-cn.com/problems/house-robber-ii/
     *
     * @param nums
     * @return int
     */
    int rob_II(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2); // 从第0个房子到倒数第2个房子
        int result2 = robRange(nums, 1, nums.size() - 1); // 从第1个房子到最后一个房子
        return max(result1, result2);
    }

private:
    // 198. 打家劫舍的逻辑
    int robRange(vector<int> &nums, int start, int end)
    {
        if (end == start)
            return nums[start];
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }

public:
    /**
     * @brief 337. 打家劫舍 III
     * @see https://leetcode-cn.com/problems/house-robber-iii/
     * @note v1: 暴力递归法（后序遍历）
     * @note T(n) = O(n^2)
     * @note S(n) = O(log n)
     * @note 会超时，因为这个递归的过程中其实是有重复计算的
     *
     * @param root
     * @return int
     */
    int rob_III(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        // 偷父节点
        int val1 = root->val;
        if (root->left)
            val1 += rob_III(root->left->left) + rob_III(root->left->right); // 跳过root->left，相当于不考虑左孩子了
        if (root->right)
            val1 += rob_III(root->right->left) + rob_III(root->right->right); // 跳过root->right，相当于不考虑右孩子了
        // 不偷父节点
        int val2 = rob_III(root->left) + rob_III(root->right); // 考虑root的左右孩子
        return max(val1, val2);
    }

    // v2: 记忆化递推法
    unordered_map<TreeNode *, int> umap; // 记录计算过的结果
    int rob_III_2(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        if (umap[root])
            return umap[root]; // 如果umap里已经有记录则直接返回

        // 偷父节点
        int val1 = root->val;
        if (root->left)
            val1 += rob_III_2(root->left->left) + rob_III_2(root->left->right); // 跳过root->left
        if (root->right)
            val1 += rob_III_2(root->right->left) + rob_III_2(root->right->right); // 跳过root->right

        // 不偷父节点
        int val2 = rob_III_2(root->left) + rob_III_2(root->right); // 考虑root的左右孩子

        umap[root] = max(val1, val2); // umap记录一下结果
        return max(val1, val2);
    }

    // v3: 动态规划法
    int rob_III_3(TreeNode *root)
    {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }

private:
    /**
     * @brief 337. 打家劫舍 III
     * @note T(n) = O(n)
     * @note S(n) = O(log n)
     * @note 注意用后序遍历的方式推导
     * @note dp数组以及下标的含义：下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱
     *
     * @param cur
     * @return vector<int> 返回的就是一个dp数组，其长度为2
     */
    vector<int> robTree(TreeNode *cur)
    {
        if (cur == nullptr)
            return vector<int>{0, 0};
        // 下标0：不偷，下标1：偷
        vector<int> left = robTree(cur->left);   // 左
        vector<int> right = robTree(cur->right); // 右
        // 中
        // 偷当前节点，那么左右孩子就不能偷了
        int val1 = cur->val + left[0] + right[0];
        // 不偷当前节点，那么左右孩子可以偷也可以不偷，取最大值
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{val2, val1};
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};