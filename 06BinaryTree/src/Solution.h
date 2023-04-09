#pragma
#include <cstdio>
#include <vector>
using std::vector;

struct TreeNode;
class Node;
class Solution
{
public:
    // 二叉树的深度遍历算法：
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

    // 二叉树的广度遍历算法：
    // 102. 二叉树的层序遍历 https://leetcode.cn/problems/binary-tree-level-order-traversal/
    vector<vector<int>> levelOrder(TreeNode *root);   // 队列法
    vector<vector<int>> levelOrder_2(TreeNode *root); // 递归法
    // 107. 二叉树的层次遍历II https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
    vector<vector<int>> levelOrderBottom(TreeNode *root);
    // 199. 二叉树的右视图 https://leetcode.cn/problems/binary-tree-right-side-view/
    vector<int> rightSideView(TreeNode *root);
    vector<int> rightSideView_2(TreeNode *root); // 递归法
    // 637. 二叉树的层平均值 https://leetcode.cn/problems/average-of-levels-in-binary-tree/
    vector<double> averageOfLevels(TreeNode *root);
    // 429. N叉树的层序遍历 https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
    vector<vector<int>> levelOrderByNTree(Node *root);
    // 515. 在每个树行中找最大值 https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
    vector<int> largestValues(TreeNode *root);

private:
    void preorder_traversal(TreeNode *cur, vector<int> &vec);  // 前序遍历
    void inorder_traversal(TreeNode *cur, vector<int> &vec);   // 中序遍历
    void postorder_traversal(TreeNode *cur, vector<int> &vec); // 后序遍历

    void order(TreeNode *cur, vector<vector<int>> &ans, int depth); // 层序遍历
    void rightSideViewOrder(TreeNode *cur, vector<int> &ans, int depth);
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

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};