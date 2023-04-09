#pragma
#include <cstdio>
#include <vector>
using std::vector;

struct TreeNode;

class Solution
{
public:
    // 144. 二叉树的前序遍历 https://leetcode.cn/problems/binary-tree-preorder-traversal/
    vector<int> preorderTraversal(TreeNode *root);   // 递归法
    vector<int> preorderTraversal_2(TreeNode *root); // 迭代法
    vector<int> preorderTraversal_3(TreeNode *root); // 统一迭代法
    // 94. 二叉树的中序遍历 https://leetcode.cn/problems/binary-tree-inorder-traversal/
    vector<int> inorderTraversal(TreeNode *root);   // 递归法
    vector<int> inorderTraversal_2(TreeNode *root); // 迭代法
    vector<int> inorderTraversal_3(TreeNode *root); // 统一迭代法
    // 145. 二叉树的后序遍历 https://leetcode.cn/problems/binary-tree-postorder-traversal/
    vector<int> postorderTraversal(TreeNode *root);   // 递n归法
    vector<int> postorderTraversal_2(TreeNode *root); // 迭代法
    vector<int> postorderTraversal_3(TreeNode *root); // 统一迭代法

private:
    void preorder_traversal(TreeNode *cur, vector<int> &vec);  // 前序遍历
    void inorder_traversal(TreeNode *cur, vector<int> &vec);   // 中序遍历
    void postorder_traversal(TreeNode *cur, vector<int> &vec); // 后序遍历
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};