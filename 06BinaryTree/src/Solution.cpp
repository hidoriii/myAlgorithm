#include "Solution.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
using std::queue;
using std::stack;

vector<int> Solution::preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder_traversal(root, ans);
    return ans;
}

vector<int> Solution::preorderTraversal_2(TreeNode *root)
{
    if (root == nullptr)
        return {};
    stack<TreeNode *> st;
    vector<int> ans;
    st.push(root); // 先把根节点入栈
    while (!st.empty())
    {
        TreeNode *node = st.top(); // 取中间节点
        st.pop();
        ans.push_back(node->val);
        if (node->right)
            st.push(node->right); // 右（空结点不入栈）
        if (node->left)
            st.push(node->left); // 左（空结点不入栈）
    }
    return ans;
}

vector<int> Solution::preorderTraversal_3(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    if (root != NULL)
        st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != NULL)
        {
            st.pop();
            if (node->right)
                st.push(node->right); // 右
            if (node->left)
                st.push(node->left); // 左
            st.push(node);           // 中
            st.push(NULL);
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

vector<int> Solution::inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder_traversal(root, ans);
    return ans;
}

vector<int> Solution::inorderTraversal_2(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL) // 用指针来访问节点，访问到最底层
        {
            st.push(cur);    // 将访问的节点放进栈
            cur = cur->left; // 左
        }
        else
        {
            cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            st.pop();
            ans.push_back(cur->val); // 中
            cur = cur->right;        // 右
        }
    }
    return ans;
}

vector<int> Solution::inorderTraversal_3(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    if (root != NULL)
    {
        st.push(root);
    }
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != NULL)
        {
            st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
            if (node->right)
            {
                st.push(node->right); // 添加右节点（空节点不入栈）
            }
            st.push(node); // 添加中节点
            st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
            if (node->left)
            {
                st.push(node->left); // 添加左节点（空节点不入栈）
            }
        }
        else
        {                    // 只有遇到空节点的时候，才将下一个节点放进结果集
            st.pop();        // 将空节点弹出
            node = st.top(); // 重新取出栈中元素
            st.pop();
            ans.push_back(node->val); // 加入到结果集
        }
    }
    return ans;
}

vector<int> Solution::postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder_traversal(root, ans);
    return ans;
}

vector<int> Solution::postorderTraversal_2(TreeNode *root)
{
    stack<TreeNode *> st;
    vector<int> ans;
    if (root == NULL)
        return ans;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        ans.push_back(node->val);
        if (node->left)
            st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
        if (node->right)
            st.push(node->right); // 空节点不入栈
    }
    std::reverse(ans.begin(), ans.end()); // 将结果反转之后就是左右中的顺序了
    return ans;
}

vector<int> Solution::postorderTraversal_3(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> st;
    if (root != NULL)
        st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        if (node != NULL)
        {
            st.pop();
            st.push(node); // 中
            st.push(NULL);

            if (node->right)
                st.push(node->right); // 右
            if (node->left)
                st.push(node->left); // 左
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);
        }
    }
    return result;
}

vector<vector<int>> Solution::levelOrder(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root != nullptr)
        que.push(root);
    vector<vector<int>> ans;
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *cur = que.front(); // 事先记录要弹出的结点
            que.pop();
            vec.push_back(cur->val); // 收集当前层结点
            if (cur->left)           // 如果要弹出的结点存在 左/右 子节点，则 push到 que中
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }
        ans.push_back(vec); // 将当前层添加到 ans中
    }
    return ans;
}

vector<vector<int>> Solution::levelOrder_2(TreeNode *root)
{
    vector<vector<int>> ans;
    int depth = 0;
    order(root, ans, depth);
    return ans;
}

vector<vector<int>> Solution::levelOrderBottom(TreeNode *root)
{
    queue<TreeNode *> que;
    vector<vector<int>> ans;
    if (root != nullptr)
        que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *cur = que.front();
            que.pop();
            vec.push_back(cur->val);
            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }
        ans.push_back(vec);
    }
    std::reverse(ans.begin(), ans.end()); // 反转 vector
    return ans;
}

vector<int> Solution::rightSideView(TreeNode *root)
{
    queue<TreeNode *> que;
    vector<vector<int>> tmp;
    if (root != nullptr)
        que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *cur = que.front();
            que.pop();
            vec.push_back(cur->val);
            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }
        tmp.push_back(vec);
    }
    vector<int> ans;
    for (auto vec : tmp)
    {
        ans.push_back(vec.back()); // 取每层结点中的最后一个结点
    }
    return ans;
}

vector<int> Solution::rightSideView_2(TreeNode *root)
{
    vector<int> ans;
    rightSideViewOrder(root, ans, 0);
    return ans;
}

vector<double> Solution::averageOfLevels(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root != nullptr)
        que.push(root);
    vector<double> ans;
    while (!que.empty())
    {
        int size = que.size();
        double sum = 0.0;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *cur = que.front();
            que.pop();
            sum += cur->val;
            if (cur->left)
                que.push(cur->left);
            if (cur->right)
                que.push(cur->right);
        }
        ans.push_back(sum / size); // 将当前层的平均值添加到 ans中
    }
    return ans;
}

vector<vector<int>> Solution::levelOrderByNTree(Node *root)
{
    queue<Node *> que;
    vector<vector<int>> ans;
    if (root)
    {
        que.push(root);
    }
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; ++i)
        {
            Node *cur = que.front();
            que.pop();
            vec.push_back(cur->val);
            if (!cur->children.empty())
            {
                for (auto node : cur->children)
                {
                    que.push(node);
                }
            }
        }
        ans.push_back(vec);
    }
    return ans;
}

vector<int> Solution::largestValues(TreeNode *root)
{
    queue<TreeNode *> que;
    if (root)
        que.push(root);
    vector<int> ans;
    while (!que.empty())
    {
        
    }
    return ans;
}

// private function members:

void Solution::preorder_traversal(TreeNode *cur, vector<int> &vec)
{
    if (cur == NULL)
        return;
    vec.push_back(cur->val);             // 中
    preorder_traversal(cur->left, vec);  // 左
    preorder_traversal(cur->right, vec); // 右
}

void Solution::inorder_traversal(TreeNode *cur, vector<int> &vec)
{
    if (cur == NULL)
        return;
    preorder_traversal(cur->left, vec);  // 左
    vec.push_back(cur->val);             // 中
    preorder_traversal(cur->right, vec); // 右
}

void Solution::postorder_traversal(TreeNode *cur, vector<int> &vec)
{
    if (cur == NULL)
        return;
    preorder_traversal(cur->left, vec);  // 左
    preorder_traversal(cur->right, vec); // 右
    vec.push_back(cur->val);             // 中
}

/**
 * @brief 用于层序遍历函数 levelOrder_2 使用的递归函数
 *
 * @param cur
 * @param ans
 * @param depth
 */
void Solution::order(TreeNode *cur, vector<vector<int>> &ans, int depth)
{
    if (cur == nullptr)
    {
        return;
    }
    if (ans.size() == depth)
    {
        ans.push_back(vector<int>());
    }
    ans[depth].push_back(cur->val);
    order(cur->left, ans, depth + 1);
    order(cur->right, ans, depth + 1);
}

void Solution::rightSideViewOrder(TreeNode *cur, vector<int> &ans, int depth)
{
    if (cur == nullptr)
        return;
    // 先访问 当前节点，再递归地访问 右子树 和 左子树
    if (depth == ans.size())
    { // 如果当前节点所在深度还没有出现在 ans里，说明在该深度下当前节点是第一个被访问的节点，因此将当前节点加入 ans中
        ans.push_back(cur->val);
    }
    depth++;
    rightSideViewOrder(cur->right, ans, depth);
    rightSideViewOrder(cur->left, ans, depth);
}
