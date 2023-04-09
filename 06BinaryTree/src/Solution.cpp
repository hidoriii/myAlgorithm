#include "Solution.h"
#include <stack>
#include <algorithm>
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
