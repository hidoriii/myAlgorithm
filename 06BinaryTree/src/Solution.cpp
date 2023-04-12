#include "Solution.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
using std::queue;
using std::stack;


vector<int> Solution::preorderTraversal(TreeNode* root)
{
	vector<int> ans;
	preorder_traversal(root, ans);
	return ans;
}

vector<int> Solution::preorderTraversal_2(TreeNode* root)
{
	if (root == nullptr)
		return {};
	stack<TreeNode*> st;
	vector<int> ans;
	st.push(root); // 先把根节点入栈
	while (!st.empty())
	{
		TreeNode* node = st.top(); // 取中间节点
		st.pop();
		ans.push_back(node->val);
		if (node->right)
			st.push(node->right); // 右（空结点不入栈）
		if (node->left)
			st.push(node->left); // 左（空结点不入栈）
	}
	return ans;
}

vector<int> Solution::preorderTraversal_3(TreeNode* root)
{
	vector<int> result;
	stack<TreeNode*> st;
	if (root != NULL)
		st.push(root);
	while (!st.empty())
	{
		TreeNode* node = st.top();
		if (node != NULL)
		{
			st.pop();
			if (node->right)
				st.push(node->right); // 右
			if (node->left)
				st.push(node->left); // 左
			st.push(node); // 中
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

vector<int> Solution::inorderTraversal(TreeNode* root)
{
	vector<int> ans;
	inorder_traversal(root, ans);
	return ans;
}

vector<int> Solution::inorderTraversal_2(TreeNode* root)
{
	vector<int> ans;
	stack<TreeNode*> st;
	TreeNode* cur = root;
	while (cur != NULL || !st.empty())
	{
		if (cur != NULL) // 用指针来访问节点，访问到最底层
		{
			st.push(cur); // 将访问的节点放进栈
			cur = cur->left; // 左
		}
		else
		{
			cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
			st.pop();
			ans.push_back(cur->val); // 中
			cur = cur->right; // 右
		}
	}
	return ans;
}

vector<int> Solution::inorderTraversal_3(TreeNode* root)
{
	vector<int> ans;
	stack<TreeNode*> st;
	if (root != NULL)
	{
		st.push(root);
	}
	while (!st.empty())
	{
		TreeNode* node = st.top();
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
		{
			// 只有遇到空节点的时候，才将下一个节点放进结果集
			st.pop(); // 将空节点弹出
			node = st.top(); // 重新取出栈中元素
			st.pop();
			ans.push_back(node->val); // 加入到结果集
		}
	}
	return ans;
}

vector<int> Solution::postorderTraversal(TreeNode* root)
{
	vector<int> ans;
	postorder_traversal(root, ans);
	return ans;
}

vector<int> Solution::postorderTraversal_2(TreeNode* root)
{
	stack<TreeNode*> st;
	vector<int> ans;
	if (root == NULL)
		return ans;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* node = st.top();
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

vector<int> Solution::postorderTraversal_3(TreeNode* root)
{
	vector<int> result;
	stack<TreeNode*> st;
	if (root != NULL)
		st.push(root);
	while (!st.empty())
	{
		TreeNode* node = st.top();
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

vector<vector<int>> Solution::levelOrder(TreeNode* root)
{
	queue<TreeNode*> que;
	if (root != nullptr)
		que.push(root);
	vector<vector<int>> ans;
	while (!que.empty())
	{
		int size = que.size();
		vector<int> vec;
		for (int i = 0; i < size; ++i)
		{
			TreeNode* cur = que.front(); // 事先记录要弹出的结点
			que.pop();
			vec.push_back(cur->val); // 收集当前层结点
			if (cur->left) // 如果要弹出的结点存在 左/右 子节点，则 push到 que中
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
		ans.push_back(vec); // 将当前层添加到 ans中
	}
	return ans;
}

vector<vector<int>> Solution::levelOrder_2(TreeNode* root)
{
	vector<vector<int>> ans;
	int depth = 0;
	order(root, ans, depth);
	return ans;
}

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root)
{
	queue<TreeNode*> que;
	vector<vector<int>> ans;
	if (root != nullptr)
		que.push(root);
	while (!que.empty())
	{
		int size = que.size();
		vector<int> vec;
		for (int i = 0; i < size; ++i)
		{
			TreeNode* cur = que.front();
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

vector<int> Solution::rightSideView(TreeNode* root)
{
	queue<TreeNode*> que;
	vector<vector<int>> tmp;
	if (root != nullptr)
		que.push(root);
	while (!que.empty())
	{
		int size = que.size();
		vector<int> vec;
		for (int i = 0; i < size; ++i)
		{
			TreeNode* cur = que.front();
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

vector<int> Solution::rightSideView_2(TreeNode* root)
{
	vector<int> ans;
	rightSideViewOrder(root, ans, 0);
	return ans;
}

vector<double> Solution::averageOfLevels(TreeNode* root)
{
	queue<TreeNode*> que;
	if (root != nullptr)
		que.push(root);
	vector<double> ans;
	while (!que.empty())
	{
		int size = que.size();
		double sum = 0.0;
		for (int i = 0; i < size; ++i)
		{
			TreeNode* cur = que.front();
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

vector<vector<int>> Solution::levelOrderByNTree(NNode* root)
{
	queue<NNode*> que;
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
			NNode* cur = que.front();
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

vector<int> Solution::largestValues(TreeNode* root)
{
	queue<TreeNode*> que;
	if (root)
		que.push(root);
	vector<int> ans;
	while (!que.empty())
	{
		int size = que.size();
		TreeNode* tmp = que.front(); // 取第一个结点假设为最大值
		int max = tmp->val;
		if (tmp->left) // 需要单独判断该结点是否存在子结点，存在则入列
		{
			que.push(tmp->left);
		}
		if (tmp->right)
		{
			que.push(tmp->right);
		}
		que.pop(); // 处理完第一个结点后，第一个结点出列

		for (int i = 0; i < size - 1; ++i) // 将假定的最大值与剩余结点进行比较，注意 size要减一
		{
			TreeNode* cur = que.front();
			que.pop();
			max = std::max(max, cur->val); // 更新 max的值
			if (cur->left)
			{
				que.push(cur->left);
			}
			if (cur->right)
			{
				que.push(cur->right);
			}
		}
		ans.push_back(max);
	}
	return ans;
}

Node* Solution::connect(Node* root)
{
	queue<Node*> que;
	if (root)
	{
		que.push(root);
	}
	// 外层的 while 循环迭代的是层数
	while (!que.empty())
	{
		int size = que.size(); // 记录当前队列大小
		for (int i = 0; i < size; ++i)
		{
			Node* cur = que.front(); // 从队首取出元素
			que.pop();
			if (i < size - 1)
			{
				cur->next = que.front(); // 连接
			}
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
	}
	return root;
}

Node* Solution::connect_II(Node* root) // 与上题一模一样
{
	connect(root);
	return root;
}

int Solution::maxDepth(TreeNode* root)
{
	queue<TreeNode*> que;
	int ans = 0;
	if (root)
	{
		que.push(root);
	}
	while (!que.empty())
	{
		ans++; // 队列中存在结点 ans就自增一次
		int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode* cur = que.front();
			que.pop();
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
	}
	return ans;
}

int Solution::minDepth(TreeNode* root)
{
	queue<std::pair<TreeNode*, int>> que;
	if (root)
	{
		que.push({root, 1});
	}
	while (!que.empty())
	{
		TreeNode* node = que.front().first;
		int depth = que.front().second;
		que.pop();
		if (node->left == nullptr && node->right == nullptr) // 当左右孩子都为空的时候，说明是最低点的一层了，退出
		{
			return depth;
		}
		if (node->left != nullptr)
		{
			que.emplace(node->left, depth + 1);
		}
		if (node->right != nullptr)
		{
			que.emplace(node->right, depth + 1);
		}
	}
	return 0;
}

int Solution::minDepth_2(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		return 1;
	}

	int min_depth = INT_MAX;
	if (root->left != nullptr)
	{
		min_depth = std::min(minDepth(root->left), min_depth);
	}
	if (root->right != nullptr)
	{
		min_depth = std::min(minDepth(root->right), min_depth);
	}

	return min_depth + 1;
}

int Solution::minDepthByPos(TreeNode* root)
{
	return getMinDepthByPos(root);
}

int Solution::minDepthByPre(TreeNode* root)
{
	if (root == NULL)
		return 0;
	result = INT_MAX;
	getMinDepthByPre(root, 1);
	return result;
}

int Solution::countNodes(TreeNode* root)
{
	return getNodesNumByPos(root);
}

int Solution::countNodes_2(TreeNode* root)
{
	queue<TreeNode*> que;
	if (root)
	{
		que.push(root);
	}
	int result = 0;
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode* cur = que.front();
			que.pop();
			++result; // 记录结点数量
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
	}
	return result;
}

int Solution::countNodes_3(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	int leftDepth = 0, rightDepth = 0; // 这里初始为0是有目的的，为了下面求指数方便

	while (left) // 求左子树深度
	{
		left = left->left;
		++leftDepth;
	}
	while (right) // 求右子树深度
	{
		right = right->right;
		++rightDepth;
	}
	if (leftDepth == rightDepth)
	{
		return (2 << leftDepth) - 1; // 注意(2<<1) 相当于2^2，所以leftDepth初始为0
	}
	return countNodes_3(root->left) + countNodes_3(root->right) + 1;
}

bool Solution::isBalanced(TreeNode* root)
{
	return getHeightByPos(root) == -1 ? false : true;
}

bool Solution::isBalanced_2(TreeNode* root)
{
	stack<TreeNode*> st;
	if (root == NULL)
		return true;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* cur = st.top(); // 中
		st.pop();
		if (abs(getMaxDepthByStack(cur->left) - getMaxDepthByStack(cur->right)) > 1)
		{
			// 判断左右孩子高度是否符合
			return false;
		}
		if (cur->right) // 右（空节点不入栈）
			st.push(cur->right);
		if (cur->left) // 左（空节点不入栈）
			st.push(cur->left);
	}
	return true;
}

TreeNode* Solution::invertTree(TreeNode* root)
{
	if (root == nullptr) // 确定递归终止条件：碰到 nullptr就直接 return
		return root;
	std::swap(root->left, root->right); // 中（交换当前结点的左、右子结点）
	invertTree(root->left); // 左
	invertTree(root->right); // 右
	// std::swap(root->left, root->right); // 把这句代码放在这里就变成了后序遍历，也是可以解出来这题的
	return root;
}

TreeNode* Solution::invertTree_2(TreeNode* root)
{
	if (root == nullptr)
		return root;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* cur = st.top();
		st.pop();
		std::swap(cur->left, cur->right);
		if (cur->right)
			st.push(cur->right);
		if (cur->left)
			st.push(cur->left);
	}
	return root;
}

TreeNode* Solution::invertTree_3(TreeNode* root)
{
	stack<TreeNode*> st;
	if (root != NULL)
		st.push(root);
	while (!st.empty())
	{
		TreeNode* node = st.top();
		if (node != NULL)
		{
			st.pop();
			if (node->right)
				st.push(node->right); // 右
			if (node->left)
				st.push(node->left); // 左
			st.push(node); // 中
			st.push(nullptr);
		}
		else
		{
			st.pop();
			node = st.top();
			st.pop();
			std::swap(node->left, node->right); // 节点处理逻辑
		}
	}
	return root;
}

TreeNode* Solution::invertTree_4(TreeNode* root)
{
	queue<TreeNode*> que;
	if (root)
		que.push(root);
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode* cur = que.front();
			que.pop();
			std::swap(cur->left, cur->right); // 交换 cur的左、右结点
			if (cur->left)
				que.push(cur->left);
			if (cur->right)
				que.push(cur->right);
		}
	}
	return root;
}

TreeNode* Solution::invertTree_5(TreeNode* root)
{
	if (root == nullptr)
		return root;
	invertTree(root->left); // 左
	std::swap(root->left, root->right); // 中
	invertTree(root->left); // 注意 这里依然要遍历左子树 因为中间节点已经翻转了
	return root;
}

TreeNode* Solution::invertTree_6(TreeNode* root)
{
	stack<TreeNode*> st;
	if (root != nullptr)
		st.push(root);
	while (!st.empty())
	{
		TreeNode* node = st.top();
		if (node)
		{
			st.pop();
			if (node->right)
				st.push(node->right); // 右
			st.push(node); // 中
			st.push(nullptr);
			if (node->left)
				st.push(node->left); // 左
		}
		else
		{
			st.pop();
			node = st.top();
			st.pop();
			std::swap(node->left, node->right); // 节点处理逻辑
		}
	}
	return root;
}

vector<int> Solution::morrisPre(TreeNode* root)
{
	if (root == nullptr)
		return {};
	vector<int> ans;
	TreeNode *cur = root, // cur表示当前结点
	         *mostRight = nullptr; // mostRight表示 cur的左孩子的最右结点
	while (cur != nullptr)
	{
		mostRight = cur->left;
		if (mostRight != nullptr) // 若 cur有左孩子，找到 cur左子树的最右结点
		{
			while (mostRight->right != nullptr && mostRight->right != cur)
			{
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr) // mostRight的右孩子指向空，让其指向 cur， cur向左移动
			{
				mostRight->right = cur;
				ans.push_back(cur->val);
				cur = cur->left;
				continue;
			}
			else // mostRight的右孩子指向 cur，让其指向空， cur向右移动
			{
				mostRight->right = nullptr;
			}
		}
		else
		{
			ans.push_back(cur->val);
		}
		cur = cur->right;
	}
	return ans;
}

vector<int> Solution::morrisIn(TreeNode* root)
{
	if (root == nullptr)
		return {};
	vector<int> ans;
	TreeNode *cur = root,
	         *mostRight = nullptr;
	while (cur)
	{
		mostRight = cur->left;
		if (mostRight)
		{
			while (mostRight->right && mostRight->right != cur)
			{
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr)
			{
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else
			{
				mostRight->right = nullptr;
			}
		}
		ans.push_back(cur->val);
		cur = cur->right;
	}
	return ans;
}

vector<int> Solution::morrisPos(TreeNode* root)
{
	if (root == nullptr)
		return {};
	vector<int> ans;
	TreeNode *cur = root,
	         *mostRight = nullptr;
	while (cur)
	{
		mostRight = cur->left;
		if (mostRight)
		{
			while (mostRight->right && mostRight->right != cur)
			{
				mostRight = mostRight->right;
			}
			if (mostRight->right == nullptr)
			{
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else
			{
				mostRight->right = nullptr;
				dealEdge(cur->left, ans);
			}
		}
		cur = cur->right;
	}
	dealEdge(root, ans);
	return ans;
}

bool Solution::isSymmetric(TreeNode* root)
{
	if (root == nullptr)
		return true;
	return compare(root->left, root->right);
}

bool Solution::isSymmetric_2(TreeNode* root)
{
	if (root == nullptr)
		return true;
	queue<TreeNode*> que;
	que.push(root->left); // 将左子树头结点加入队列
	que.push(root->right); // 将右子树头结点加入队列
	while (!que.empty()) // 接下来就要判断这两个树是否相互翻转
	{
		TreeNode* leftNode = que.front();
		que.pop();
		TreeNode* rightNode = que.front();
		que.pop();
		if (!leftNode && !rightNode) // 左节点为空、右节点为空，此时说明是对称的
		{
			continue;
		}
		// 左右一个节点不为空，或者都不为空但数值不相同，返回false
		if ((!leftNode || !rightNode || (leftNode->val != rightNode->val)))
		{
			return false;
		}
		que.push(leftNode->left); // 加入左节点左孩子
		que.push(rightNode->right); // 加入右节点右孩子
		que.push(leftNode->right); // 加入左节点右孩子
		que.push(rightNode->left); // 加入右节点左孩子
	}
	return true;
}

bool Solution::isSymmetric_3(TreeNode* root)
{
	// 只要把 队列(queue) 原封不动的改成 栈(stack) 就可以了
	if (root == nullptr)
		return true;
	stack<TreeNode*> st;
	st.push(root->left);
	st.push(root->right);
	while (!st.empty())
	{
		TreeNode* leftNode = st.top();
		st.pop();
		TreeNode* rightNode = st.top();
		st.pop();
		if (!leftNode && !rightNode) // 左节点为空、右节点为空，此时说明是对称的
		{
			continue;
		}
		if ((!leftNode || !rightNode || (leftNode->val != rightNode->val)))
		{
			return false;
		}
		st.push(leftNode->left);
		st.push(rightNode->right);
		st.push(leftNode->right);
		st.push(rightNode->left);
	}
	return true;
}

bool Solution::isSameTree(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)
		return true;
	else if (p == nullptr || q == nullptr)
		return false;
	else if (p->val != q->val)
		return false;
	else
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool Solution::isSameTree_2(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && q == nullptr)
		return true;
	else if (p == nullptr || q == nullptr)
		return false;
	queue<TreeNode*> queue1, queue2;
	queue1.push(p);
	queue2.push(q);
	while (!queue1.empty() && !queue2.empty())
	{
		auto node1 = queue1.front();
		queue1.pop();
		auto node2 = queue2.front();
		queue2.pop();
		if (node1->val != node2->val)
		{
			return false;
		}
		auto left1 = node1->left, right1 = node1->right, left2 = node2->left, right2 = node2->right;
		if ((left1 == nullptr) ^ (left2 == nullptr))
		{
			return false;
		}
		if ((right1 == nullptr) ^ (right2 == nullptr))
		{
			return false;
		}
		if (left1 != nullptr)
		{
			queue1.push(left1);
		}
		if (right1 != nullptr)
		{
			queue1.push(right1);
		}
		if (left2 != nullptr)
		{
			queue2.push(left2);
		}
		if (right2 != nullptr)
		{
			queue2.push(right2);
		}
	}
	return queue1.empty() && queue2.empty();
}

bool Solution::isSubtree(TreeNode* root, TreeNode* subRoot)
{
	return dfs(root, subRoot);
}

bool Solution::isSubtree_2(TreeNode* root, TreeNode* subRoot)
{
	int maxElement = INT_MIN;
	getMaxElement(root, maxElement);
	getMaxElement(subRoot, maxElement);
	vector<int> sOrder, tOrder;
	int lNull = maxElement + 1,
	    rNull = maxElement + 2;
	getDfsOrder(root, sOrder, lNull, rNull);
	getDfsOrder(subRoot, tOrder, lNull, rNull);
	return kmp(sOrder, tOrder);
}

void Solution::getPrime()
{
	vis[0] = vis[1] = 1;
	tot = 0;
	for (int i = 2; i < MAX_N; ++i)
	{
		if (!vis[i])
			p[++tot] = i;
		for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j)
		{
			vis[i * p[j]] = 1;
			if (i % p[j] == 0)
				break;
		}
	}
}

void Solution::dfs_hash(TreeNode* o, unordered_map<TreeNode*, Status>& h)
{
	h[o] = Status(o->val, 1);
	if (!o->left && !o->right)
		return;
	if (o->left)
	{
		dfs_hash(o->left, h);
		h[o].s += h[o->left].s;
		h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
	}
	if (o->right)
	{
		dfs_hash(o->right, h);
		h[o].s += h[o->right].s;
		h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
	}
}

bool Solution::isSubtree_3(TreeNode* root, TreeNode* subRoot)
{
	getPrime();
	dfs_hash(root, hS);
	dfs_hash(subRoot, hT);
	int tHash = hT[subRoot].f;
	for (const auto& [k, v] : hS)
	{
		if (v.f == tHash)
		{
			return true;
		}
	}
	return false;
}

// 再探二叉树的最大深度：
int Solution::maxDepthByPos(TreeNode* root)
{
	return getMaxDepthByPost(root);
}

int Solution::maxDepthByPre(TreeNode* root)
{
	result = 0;
	if (root == nullptr)
		return result;
	getMaxDepthByPre(root, 1);
	return result;
}

int Solution::maxDepthInNTree(NNode* root)
{
	if (root == nullptr)
		return 0;
	int max_depth = 0;
	for (int i = 0; i < root->children.size(); ++i)
	{
		max_depth = std::max(max_depth, maxDepthInNTree(root->children[i]));
	}
	return max_depth + 1;
}

int Solution::maxDepthInNTree_2(NNode* root)
{
	queue<NNode*> que;
	if (root)
		que.push(root);
	int depth = 0;
	while (!que.empty())
	{
		int size = que.size();
		depth++; // 记录深度
		for (int i = 0; i < size; ++i)
		{
			NNode* cur = que.front();
			que.pop();
			for (auto node : cur->children)
			{
				if (node)
					que.push(node);
			}
		}
	}
	return depth;
}

// private members:

void Solution::preorder_traversal(TreeNode* cur, vector<int>& vec)
{
	if (cur == NULL)
		return;
	vec.push_back(cur->val); // 中
	preorder_traversal(cur->left, vec); // 左
	preorder_traversal(cur->right, vec); // 右
}

void Solution::inorder_traversal(TreeNode* cur, vector<int>& vec)
{
	if (cur == NULL)
		return;
	preorder_traversal(cur->left, vec); // 左
	vec.push_back(cur->val); // 中
	preorder_traversal(cur->right, vec); // 右
}

void Solution::postorder_traversal(TreeNode* cur, vector<int>& vec)
{
	if (cur == NULL)
		return;
	preorder_traversal(cur->left, vec); // 左
	preorder_traversal(cur->right, vec); // 右
	vec.push_back(cur->val); // 中
}

/**
 * @brief 用于层序遍历函数 levelOrder_2 使用的递归函数
 *
 * @param cur
 * @param ans
 * @param depth
 */
void Solution::order(TreeNode* cur, vector<vector<int>>& ans, int depth)
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

/**
 * @brief 服务于 rightSideView_2
 *
 * @param cur
 * @param ans
 * @param depth
 */
void Solution::rightSideViewOrder(TreeNode* cur, vector<int>& ans, int depth)
{
	if (cur == nullptr)
		return;
	// 先访问 当前节点，再递归地访问 右子树 和 左子树
	if (depth == ans.size())
	{
		// 如果当前节点所在深度还没有出现在 ans里，说明在该深度下当前节点是第一个被访问的节点，因此将当前节点加入 ans中
		ans.push_back(cur->val);
	}
	depth++;
	rightSideViewOrder(cur->right, ans, depth);
	rightSideViewOrder(cur->left, ans, depth);
}

/**
 * @brief 用于 morris后序遍历处理结点
 *
 * @param node
 * @param result 保存处理后的结果
 */
void Solution::dealEdge(TreeNode* node, vector<int>& result)
{
	TreeNode* tail = reverseEdge(node);
	TreeNode* cur = tail;
	while (cur)
	{
		result.push_back(cur->val);
		cur = cur->right;
	}
	reverseEdge(tail);
}

/**
 * @brief 用于反转树
 *
 * @param node
 * @return TreeNode*
 */
TreeNode* Solution::reverseEdge(TreeNode* node)
{
	TreeNode *pre = nullptr,
	         *next = nullptr;
	while (node)
	{
		next = node->right;
		node->right = pre;
		pre = node;
		node = next;
	}
	return pre;
}

bool Solution::compare(TreeNode* left, TreeNode* right)
{
	// 确定递归终止条件： 首先排除空节点的情况
	if (left == nullptr && right != nullptr)
		return false;
	else if (left != nullptr && right == nullptr)
		return false;
	else if (left == nullptr && right == nullptr)
		return true;
		// 排除了空节点，再排除数值不相同的情况
	else if (left->val != right->val) // 注意这里我没有使用else
		return false;
	// 确定单层递归的逻辑：
	// 此时就是：左右节点都不为空，且数值相同的情况
	// 此时才做递归，做下一层的判断
	bool outside = compare(left->left, right->right); // 左子树：左、 右子树：右
	bool inside = compare(left->right, right->left); // 左子树：右、 右子树：左
	bool isSame = outside && inside; // 左子树：中、 右子树：中（逻辑处理）
	return isSame;
	// 当然可以把这些代码整理的简洁一点，但是可能会隐藏掉一些逻辑，这边就不整理了
}

bool Solution::check(TreeNode* o, TreeNode* t)
{
	if (!o && !t)
	{
		return true;
	}
	if ((o && !t) || (!o && t) || (o->val != t->val))
	{
		return false;
	}
	return check(o->left, t->left) && check(o->right, t->right);
}

bool Solution::dfs(TreeNode* o, TreeNode* t)
{
	if (!o)
	{
		return false;
	}
	return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
}

void Solution::getMaxElement(TreeNode* node, int& maxElement)
{
	if (!node)
	{
		return;
	}
	maxElement = std::max(maxElement, node->val);
	getMaxElement(node->left, maxElement);
	getMaxElement(node->right, maxElement);
}

void Solution::getDfsOrder(TreeNode* node, vector<int>& tar, int& lNull, int& rNull)
{
	if (!node)
	{
		return;
	}
	tar.push_back(node->val);
	if (node->left)
	{
		getDfsOrder(node->left, tar, lNull, rNull);
	}
	else
	{
		tar.push_back(lNull);
	}
	if (node->right)
	{
		getDfsOrder(node->right, tar, lNull, rNull);
	}
	else
	{
		tar.push_back(rNull);
	}
}

bool Solution::kmp(vector<int>& sOrder, vector<int>& tOrder)
{
	int sLen = sOrder.size(), tLen = tOrder.size();
	vector<int> fail(tLen, -1);
	for (int i = 1, j = -1; i < tLen; ++i)
	{
		while (j != -1 && tOrder[i] != tOrder[j + 1])
		{
			j = fail[j];
		}
		if (tOrder[i] == tOrder[j + 1])
		{
			++j;
		}
		fail[i] = j;
	}
	for (int i = 0, j = -1; i < sLen; ++i)
	{
		while (j != -1 && sOrder[i] != tOrder[j + 1])
		{
			j = fail[j];
		}
		if (sOrder[i] == tOrder[j + 1])
		{
			++j;
		}
		if (j == tLen - 1)
		{
			return true;
		}
	}
	return false;
}

int Solution::getHeightByPos(TreeNode* node)
{
	// -1 表示已经不是平衡二叉树了，否则返回值是以该节点为根节点树的高度
	if (node == nullptr)
		return 0;
	int leftHeight = getHeightByPos(node->left); // 左
	if (leftHeight == -1)
		return -1;
	int rightHeight = getHeightByPos(node->right); // 右
	if (rightHeight == -1)
		return -1;
	int height;
	if (std::abs(leftHeight - rightHeight) > 1) // 中
	{
		height = -1;
	}
	else
	{
		height = 1 + std::max(leftHeight, rightHeight); // 以当前节点为根节点的树的最大高度
	}
	return height;
	// 简写后：
	// return std::abs(leftHeight - rightHeight) > 1 ? -1 : 1 + std::max(leftHeight, rightHeight);
}

int Solution::getMaxDepthByPost(TreeNode* node)
{
	
	if (node == nullptr)
		return 0;
	int leftDepth = getMaxDepthByPost(node->left);
	int rightDepth = getMaxDepthByPost(node->right);
	int max_depth = 1 + std::max(leftDepth, rightDepth);
	return max_depth;
}

void Solution::getMaxDepthByPre(TreeNode* node, int depth)
{
	result = depth > result ? depth : result; // 中
	if (node->left == nullptr && node->right == nullptr)
		return;
	if (node->left) // 左
	{
		depth++; // 深度+1
		getMaxDepthByPre(node->left, depth);
		depth--; // 回溯，深度-1
	}
	if (node->right) // 右
	{
		depth++; // 深度+1
		getMaxDepthByPre(node->right, depth);
		depth--; // 回溯，深度-1
	}
	return;
}

int Solution::getMinDepthByPos(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	int leftDepth = getMinDepthByPos(node->left); // 左
	int rightDepth = getMinDepthByPos(node->right); // 右
	// 中
	// 当一个左子树为空，右不为空，这时并不是最低点
	if (node->left == NULL && node->right != NULL)
	{
		return 1 + rightDepth;
	}
	// 当一个右子树为空，左不为空，这时并不是最低点
	if (node->left != NULL && node->right == NULL)
	{
		return 1 + leftDepth;
	}
	int result = 1 + std::min(leftDepth, rightDepth);
	return result;
}

void Solution::getMinDepthByPre(TreeNode* node, int depth)
{
	if (node->left == nullptr && node->right == nullptr)
	{
		result = std::min(depth, result);
		return;
	}
	// 中 只不过中没有处理的逻辑
	if (node->left) // 左
	{
		getMinDepthByPre(node->left, depth + 1);
	}
	if (node->right) // 右
	{
		getMinDepthByPre(node->right, depth + 1);
	}
	return;
}

int Solution::getNodesNumByPos(TreeNode* node)
{
	if (node == nullptr)
		return 0;
	int leftNum = getNodesNumByPos(node->left); // 左
	int rightNum = getNodesNumByPos(node->right); // 右
	int treeNum = leftNum + rightNum + 1; // 中
	return treeNum;
}

int Solution::getMaxDepthByStack(TreeNode* node)
{
	// node节点的最大深度，就是cur的高度

	stack<TreeNode*> st;
	if (node != nullptr)
		st.push(node);
	int depth = 0; // 记录深度
	int ans = 0;
	while (!st.empty())
	{
		TreeNode* cur = st.top();
		if (cur != nullptr)
		{
			st.pop();
			st.push(cur); // 中
			st.push(nullptr);
			depth++;
			if (cur->right) // 右
				st.push(cur->right);
			if (node->left) // 左
				st.push(cur->left);
		}
		else
		{
			st.pop();
			cur = st.top();
			st.pop();
			depth--;
		}
		ans = ans > depth ? ans : depth;
	}
	return ans;
}
