#include <iostream>
#include "Solution2.h"
using std::cout;
using std::endl;

int Solution2::sumOfLeftLeaves(TreeNode *root)
{
	if (!root)
		return 0;
	if (root->left == nullptr && root->right == nullptr)
		return 0;
	int leftValue = sumOfLeftLeaves(root->left);			   // 左
	if (root->left && !root->left->left && !root->left->right) // 左子树就是一个左叶子的情况
	{
		leftValue = root->left->val;
	}
	int rightValue = sumOfLeftLeaves(root->right); // 右
	int sum = leftValue + rightValue;			   // 中
	return sum;
}

int Solution2::sumOfLeftLeaves_2(TreeNode *root)
{
	if (root == NULL)
		return 0;
	stack<TreeNode *> st;
	st.push(root);
	int result = 0;
	while (!st.empty())
	{
		TreeNode *node = st.top();
		st.pop();
		if (node->left != NULL && node->left->left == NULL && node->left->right == NULL)
		{
			result += node->left->val;
		}
		if (node->right)
			st.push(node->right);
		if (node->left)
			st.push(node->left);
	}
	return result;
}

int Solution2::findBottomLeftValue(TreeNode *root)
{
	if (!root)
		return 0;
	std::queue<TreeNode *> que;
	que.push(root);
	int result; // 记录每层最左结点的地址
	while (!que.empty())
	{
		int size = que.size();
		for (int i = 0; i < size; ++i)
		{
			TreeNode *node = que.front();
			que.pop();
			if (i == 0)
				result = node->val; // 更新最左结点
			if (node->left)
				que.push(node->left);
			if (node->right)
				que.push(node->right);
		}
	}
	return result;
}

int Solution2::findBottomLeftValue_2(TreeNode *root)
{
	traversal(root, 0);
	return result;
}

bool Solution2::hasPathSum(TreeNode *root, int targetSum)
{
	if (root == nullptr)
		return false;
	return traversal_2(root, targetSum - root->val);
}

bool Solution2::hasPathSum_2(TreeNode *root, int targetSum)
{
	if (root == nullptr)
		return false;
	// 此时栈里要放的是pair<节点指针，路径数值>
	stack<std::pair<TreeNode *, int>> st;
	st.push(std::make_pair(root, root->val));
	while (!st.empty())
	{
		std::pair<TreeNode *, int> node = st.top();
		st.pop();
		// 如果该节点是叶子节点了，同时该节点的路径数值等于sum，那么就返回true
		if (!node.first->left && !node.first->right && node.second == targetSum)
			return true;
		if (node.first->right) // 右节点，压进去一个节点的时候，将该节点的路径数值也记录下来
		{
			st.push({node.first->right, node.second + node.first->right->val});
		}
		if (node.first->left) // 左节点，压进去一个节点的时候，将该节点的路径数值也记录下来
		{
			st.push({node.first->left, node.second + node.first->left->val});
		}
	}
	return false;
}

vector<vector<int>> Solution2::pathSum(TreeNode *root, int targetSum)
{
	vector<vector<int>> result;
	if (!root)
		return result;
	vector<int> path;
	path.push_back(root->val); // 把根节点放进路径
	traversal_3(root, targetSum - root->val, path, result);
	return result;
}

TreeNode *Solution2::buildTree(vector<int> &inorder, vector<int> &postorder)
{
	if (inorder.size() == 0 || postorder.size() == 0)
		return nullptr;
	return traversal_4(inorder, postorder);
	// return traversal_5(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}

TreeNode *Solution2::buildTreeII(vector<int> &preorder, vector<int> &inorder)
{
	if (inorder.size() == 0 || preorder.size() == 0)
		return nullptr;
	// 参数坚持左闭右开的原则
	return traversal_6(inorder, 0, inorder.size(), preorder, 0, preorder.size());
}

TreeNode *Solution2::constructMaximumBinaryTree(vector<int> &nums)
{
	TreeNode *node = new TreeNode(0);
	if (nums.size() == 1)
	{
		node->val = nums[0];
		return node;
	}
	// 找到数组中最大的值和对应的下标
	int maxValue = 0, maxValueIndex = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > maxValue)
		{
			maxValue = nums[i];
			maxValueIndex = i;
		}
	}
	node->val = maxValue;
	// 构造左子树
	if (maxValueIndex > 0)
	{
		// 这里加了判断是为了不让空节点进入递归
		vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
		node->left = constructMaximumBinaryTree(newVec);
	}
	// 构造右子树
	if (maxValueIndex < (nums.size() - 1))
	{
		// 这里加了判断是为了不让空节点进入递归
		vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
		node->right = constructMaximumBinaryTree(newVec);
	}
	return node;
}

TreeNode *Solution2::constructMaximumBinaryTree_2(vector<int> &nums)
{
	return traversal_7(nums, 0, nums.size());
}

TreeNode *Solution2::mergeTrees(TreeNode *root1, TreeNode *root2)
{
	if (!root1)
		return root2; // 如果 root1为空，合并之后就应该是 root2
	if (!root2)
		return root1; // 如果 root2为空，合并之后就应该是 root1
	// 修改 root1的数值和结构
	root1->val += root2->val;							   // 中
	root1->left = mergeTrees(root1->left, root2->left);	   // 左
	root1->right = mergeTrees(root1->right, root2->right); // 右
	return root1;
}

TreeNode *Solution2::mergeTrees_2(TreeNode *root1, TreeNode *root2)
{
	if (root1 == nullptr)
		return root2;
	if (root2 == nullptr)
		return root1;
	queue<TreeNode *> que;
	que.push(root1);
	que.push(root2);
	while (!que.empty())
	{
		TreeNode *node1 = que.front();
		que.pop();
		TreeNode *node2 = que.front();
		que.pop();
		// 此时两个节点一定不为空，val相加
		node1->val += node2->val;
		// 如果两棵树左节点都不为空，加入队列
		if (node1->left && node2->left)
		{
			que.push(node1->left);
			que.push(node2->left);
		}
		// 如果两棵树右节点都不为空，加入队列
		if (node1->right && node2->right)
		{
			que.push(node1->right);
			que.push(node2->right);
		}
		// 当 node1的左节点为空，node2左节点不为空，就赋值过去
		if (!node1->left && node2->left)
		{
			node1->left = node2->left;
		}
		// 当 node1的左节点为空，node2右节点不为空，就赋值过去
		if (!node1->right && node2->right)
		{
			node1->right = node2->right;
		}
	}
	return root1;
}

TreeNode *Solution2::mergeTrees_3(TreeNode *root1, TreeNode *root2)
{
	process(&root1, &root2);
	return root1;
}

TreeNode *Solution2::searchBST(TreeNode *root, int val)
{
	if (root == nullptr || root->val == val)
		return root;
	TreeNode *result = nullptr;
	if (root->val > val)
		result = searchBST(root->left, val);
	if (root->val < val)
		result = searchBST(root->right, val);
	return result; // 最后如果都没有搜索到，就返回 NULL
}

TreeNode *Solution2::searchBST_2(TreeNode *root, int val)
{
	while (root)
	{
		if (root->val > val)
			root = root->left;
		else if (root->val < val)
			root = root->right;
		else
			return root;
	}
	return nullptr;
}

bool Solution2::isValidBST(TreeNode *root)
{
	vector<int> vec;
	traversal_8(root, vec);
	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i - 1] >= vec[i]) // 注意是大于等于，因为二叉搜索树中不能有相同元素
			return false;
	}
	return true;
}

bool Solution2::isValidBST_2(TreeNode *root)
{
	if (root == nullptr)
		return true;

	// 中序遍历，验证遍历的元素是不是从小到大
	bool left = isValidBST_2(root->left); // 左

	if (maxVal < root->val)
		maxVal = root->val; // 中
	else
		return false;

	bool right = isValidBST_2(root->right); // 右

	return left && right;
}

bool Solution2::isValidBST_3(TreeNode *root)
{
	if (root == nullptr)
		return true;
	bool left = isValidBST_3(root->left);
	if (pre && pre->val >= root->val)
		return false;
	pre = root; // 记录前一个节点
	bool right = isValidBST_3(root->right);
	return left && right;
}

bool Solution2::isValidBST_4(TreeNode *root)
{
	stack<TreeNode *> st;
	TreeNode *cur = root;
	TreeNode *pre = nullptr; // 记录前一个节点
	while (cur || !st.empty())
	{
		if (cur)
		{
			st.push(cur);
			cur = cur->left; // 左
		}
		else
		{
			cur = st.top(); // 中
			st.pop();
			if (pre && cur->val <= pre->val)
				return false;
			pre = cur;		  // 保存前一个访问的结点
			cur = cur->right; // 右
		}
	}
	return true;
}

int Solution2::getMinimumDifference(TreeNode *root)
{
	vector<int> vec;
	traversal_8(root, vec);
	if (vec.size() < 2)
		return 0; // 说明整个树中只有一个根节点
	int result = INT_MAX;
	for (int i = 1; i < vec.size(); ++i)
	{
		// 统计有序数组的最小差值
		result = std::min(result, vec[i] - vec[i - 1]);
	}
	return result;
}

int Solution2::getMinimumDifference_2(TreeNode *root)
{
	TreeNode *pre = nullptr;
	int result = INT_MAX;
	traversal_9(root, pre, result);
	return result;
}

void Solution2::update(int x)
{
	if (x == base)
	{
		++count;
	}
	else
	{
		count = 1;
		base = x;
	}
	if (count == maxCount)
	{
		answer.push_back(base);
	}
	if (count > maxCount)
	{
		maxCount = count;
		answer = vector<int>{base};
	}
}

void Solution2::dfs(TreeNode *o)
{
	if (!o)
		return;
	dfs(o->left);	// 左
	update(o->val); // 中
	dfs(o->right);	// 右
}

vector<int> Solution2::findMode(TreeNode *root)
{
	dfs(root);
	return answer;
}

void Solution2::searchBST_2(TreeNode *cur)
{
	if (cur == nullptr)
		return;

	searchBST_2(cur->left); // 左
	// 中
	if (pre == nullptr)
	{ // 第一个节点
		count = 1;
	}
	else if (pre->val == cur->val)
	{ // 与前一个节点数值相同
		count++;
	}
	else
	{ // 与前一个节点数值不同
		count = 1;
	}
	pre = cur; // 更新上一个节点

	if (count == maxCount)
	{ // 如果和最大值相同，放进 answer中
		answer.push_back(cur->val);
	}

	if (count > maxCount)
	{					  // 如果计数大于最大值频率
		maxCount = count; // 更新最大频率
		answer.clear();	  // 很关键的一步，不要忘记清空 answer，之前 answer里的元素都失效了
		answer.push_back(cur->val);
	}

	searchBST_2(cur->right); // 右
	return;
}

vector<int> Solution2::findMode_2(TreeNode *root)
{
	answer.clear();
	searchBST_2(root);
	return answer;
}

vector<int> Solution2::findMode_3(TreeNode *root)
{
	stack<TreeNode *> st;
	TreeNode *cur = root;
	while (cur != nullptr || !st.empty())
	{
		if (cur != nullptr)
		{					 // 指针来访问节点，访问到最底层
			st.push(cur);	 // 将访问的节点放进栈
			cur = cur->left; // 左
		}
		else
		{
			cur = st.top();
			st.pop(); // 中
			if (pre == nullptr)
			{ // 第一个节点
				count = 1;
			}
			else if (pre->val == cur->val)
			{ // 与前一个节点数值相同
				count++;
			}
			else
			{ // 与前一个节点数值不同
				count = 1;
			}
			if (count == maxCount)
			{ // 如果和最大值相同，放进result中
				answer.push_back(cur->val);
			}

			if (count > maxCount)
			{					  // 如果计数大于最大值频率
				maxCount = count; // 更新最大频率
				answer.clear();	  // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
				answer.push_back(cur->val);
			}
			pre = cur;
			cur = cur->right; // 右
		}
	}
	return answer;
}

vector<int> Solution2::findMode_Morris(TreeNode *root)
{
	TreeNode *cur = root, *pre = nullptr;
	while (cur)
	{
		if (!cur->left)
		{
			update(cur->val);
			cur = cur->right;
			continue;
		}
		pre = cur->left;
		while (pre->right && pre->right != cur)
		{
			pre = pre->right;
		}
		if (!pre->right)
		{
			pre->right = cur;
			cur = cur->left;
		}
		else
		{
			pre->right = nullptr;
			update(cur->val);
			cur = cur->right;
		}
	}
	return answer;
}

TreeNode *Solution2::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == p || root == q || root == nullptr)
		return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left == nullptr)
		return right;
	if (right == nullptr)
		return left;
	return root;
}

TreeNode *Solution2::lowestCommonAncestor_BST(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == nullptr)
		return root;
	if (root->val > p->val && root->val > q->val)
	{
		TreeNode *left = lowestCommonAncestor_BST(root->left, p, q);
		if (left)
		{
			return left;
		}
	}
	if (root->val < p->val && root->val < q->val)
	{
		TreeNode *right = lowestCommonAncestor_BST(root->right, p, q);
		if (right)
		{
			return right;
		}
	}
	return root;
}

TreeNode *Solution2::lowestCommonAncestor_BST_2(TreeNode *root, TreeNode *p, TreeNode *q)
{
	while (root)
	{
		if (root->val > p->val && root->val > q->val)
		{
			root = root->left;
		}
		else if (root->val < p->val && root->val < q->val)
		{
			root = root->right;
		}
		else
		{
			return root;
		}
	}
	return nullptr;
}

TreeNode *Solution2::insertIntoBST(TreeNode *root, int val)
{
	if (root == nullptr)
	{
		TreeNode *node = new TreeNode(val);
		return node;
	}
	if (root->val > val)
		root->left = insertIntoBST(root->left, val);
	if (root->val < val)
		root->right = insertIntoBST(root->right, val);
	return root;
}

TreeNode *Solution2::insertIntoBST_2(TreeNode *root, int val)
{
	parent = new TreeNode(0);
	if (root == nullptr)
	{
		root = new TreeNode(val);
	}
	traversal_10(root, val);
	return root;
}

TreeNode *Solution2::insertIntoBST_3(TreeNode *root, int val)
{
	if (root == NULL)
	{
		TreeNode *node = new TreeNode(val);
		return node;
	}
	TreeNode *cur = root;
	TreeNode *parent = root; // 这个很重要，需要记录上一个节点，否则无法赋值新节点
	while (cur != NULL)
	{
		parent = cur;
		if (cur->val > val)
			cur = cur->left;
		else
			cur = cur->right;
	}
	TreeNode *node = new TreeNode(val);
	if (val < parent->val) // 此时是用parent节点的进行赋值
		parent->left = node;
	else
		parent->right = node;
	return root;
}

TreeNode *Solution2::deleteNode(TreeNode *root, int key)
{
	if (root == nullptr) // 第一种情况：没找到删除的节点，遍历到空节点直接返回了
		return nullptr;
	if (root->val == key)
	{
		// 第二种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
		if (root->left == nullptr && root->right == nullptr)
		{
			///! 内存释放
			delete root;
			return nullptr;
		}
		// 第三种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
		else if (root->left == nullptr && root->right != nullptr)
		{
			auto retNode = root->right;
			///! 内存释放
			delete root;
			return retNode;
		}
		// 第四种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
		else if (root->left != nullptr && root->right == nullptr)
		{
			auto retNode = root->left;
			///! 内存释放
			delete root;
			return retNode;
		}
		// 第五种情况：左右孩子节点都不为空，则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置
		// 并返回删除节点右孩子为新的根节点。
		else // 最复杂的情况：左不为空，右不为空
		{
			auto cur = root->right; // 找右子树最左面的节点
			while (cur->left)		// cur一直向左移动，直到 cur->left 为空
				cur = cur->left;
			cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
			auto tmp = root;		// 把root节点保存一下，下面来删除
			root = root->right;		// 返回旧root的右孩子作为新root
			delete tmp;				// 释放节点内存（这里不写也可以，但C++最好手动释放一下吧）
			return root;
		}
	}
	if (root->val > key)
		root->left = deleteNode(root->left, key);
	if (root->val < key)
		root->right = deleteNode(root->right, key);
	return root;
}

TreeNode *Solution2::deleteNode_2(TreeNode *root, int key)
{
	if (root == nullptr)
		return root;
	TreeNode *cur = root;
	TreeNode *pre = nullptr; // 记录cur的父节点，用来删除cur
	while (cur)
	{
		if (cur->val == key)
			break;
		pre = cur;
		if (cur->val > key)
			cur = cur->left;
		else
			cur = cur->right;
	}
	if (pre == nullptr) // 如果搜索树只有头结点
	{
		return deleteOneNode(cur);
	}
	// pre 要知道是删左孩子还是右孩子
	if (pre->left && pre->left->val == key)
	{
		pre->left = deleteOneNode(cur);
	}
	if (pre->right && pre->right->val == key)
	{
		pre->right = deleteOneNode(cur);
	}
	return root;
}

TreeNode *Solution2::trimBST(TreeNode *root, int low, int high)
{
	if (root == nullptr)
		return nullptr;
	if (root->val < low)
	{
		TreeNode *right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
		return right;
	}
	if (root->val > high)
	{
		TreeNode *left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
		return left;
	}
	root->left = trimBST(root->left, low, high);   // root->left接入符合条件的左孩子
	root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
	return root;
}

TreeNode *Solution2::trimBST_2(TreeNode *root, int low, int high)
{

	if (!root)
		return nullptr;
	// 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
	while (root != nullptr && (root->val < low || root->val > high))
	{
		if (root->val < low)
			root = root->right; // 小于L往右走
		else
			root = root->left; // 大于R往左走
	}
	TreeNode *cur = root;
	// 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
	while (cur != nullptr)
	{
		while (cur->left && cur->left->val < low)
		{
			cur->left = cur->left->right;
		}
		cur = cur->left;
	}
	cur = root;

	// 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
	while (cur != nullptr)
	{
		while (cur->right && cur->right->val > high)
		{
			cur->right = cur->right->left;
		}
		cur = cur->right;
	}
	return root;
}

TreeNode *Solution2::sortedArrayToBST(vector<int> &nums)
{
	TreeNode *root = traversal_11(nums, 0, nums.size() - 1);
	return root;
}

TreeNode *Solution2::sortedArrayToBST_2(vector<int> &nums)
{
	if (nums.size() == 0)
		return nullptr;

	TreeNode *root = new TreeNode(0); // 初始根节点
	queue<TreeNode *> nodeQue;		  // 放遍历的节点
	queue<int> leftQue;				  // 保存左区间下标
	queue<int> rightQue;			  // 保存右区间下标
	nodeQue.push(root);				  // 根节点入队列
	leftQue.push(0);				  // 0为左区间下标初始位置
	rightQue.push(nums.size() - 1);	  // nums.size() - 1为右区间下标初始位置

	while (!nodeQue.empty())
	{
		TreeNode *curNode = nodeQue.front();
		nodeQue.pop();
		int left = leftQue.front();
		leftQue.pop();
		int right = rightQue.front();
		rightQue.pop();
		int mid = left + ((right - left) / 2);

		curNode->val = nums[mid]; // 将mid对应的元素给中间节点

		if (left <= mid - 1) // 处理左区间
		{
			curNode->left = new TreeNode(0);
			nodeQue.push(curNode->left);
			leftQue.push(left);
			rightQue.push(mid - 1);
		}

		if (right >= mid + 1) // 处理右区间
		{
			curNode->right = new TreeNode(0);
			nodeQue.push(curNode->right);
			leftQue.push(mid + 1);
			rightQue.push(right);
		}
	}
	return root;
}

TreeNode *Solution2::convertBST(TreeNode *root)
{
	pre = 0;
	traversal_12(root);
	return root;
}

TreeNode *Solution2::convertBST_2(TreeNode *root)
{
	pre = 0;
	traversal_13(root);
	return root;
}

// private members:

void Solution2::traversal(TreeNode *node, int depth)
{
	if (node->left == nullptr && node->right == nullptr)
	{
		if (depth > max_depth)
		{
			max_depth = depth;	// 更新最大深度
			result = node->val; // 最大深度最左面的数值
		}
		return;
	}
	// 中
	if (node->left) // 左
	{
		depth++; // 深度加一
		traversal(node->left, depth);
		depth--; // 回溯，深度减一
	}
	if (node->right) // 右
	{
		depth++;
		traversal(node->right, depth);
		depth--; // 回溯
	}
	return;
}

bool Solution2::traversal_2(TreeNode *node, int count)
{
	if (!node->left && !node->right && count == 0) // 遇到叶子节点，并且计数为0
		return true;
	if (!node->left && !node->right) // 遇到叶子节点但没有找到合适的边，直接返回
		return false;
	if (node->left) // 左 （空节点不遍历）
	{
		// 遇到叶子节点返回true，则直接返回true
		if (traversal_2(node->left, count - node->left->val)) // 注意这里有回溯的逻辑
			return true;
	}
	if (node->right) // 右 （空节点不遍历）
	{
		// 遇到叶子节点返回true，则直接返回true
		if (traversal_2(node->right, count - node->right->val)) // 注意这里有回溯的逻辑
			return true;
	}
	return false;
}

void Solution2::traversal_3(TreeNode *cur, int count, vector<int> &path, vector<vector<int>> &result)
{
	if (!cur->left && !cur->right && count == 0)
	{
		result.push_back(path);
		return;
	}
	if (!cur->left && !cur->right)
		return;
	if (cur->left) // 左（空结点不遍历）
	{
		path.push_back(cur->left->val);
		count -= cur->left->val;
		traversal_3(cur->left, count, path, result); // 递归
		count += cur->left->val;					 // 回溯
		path.pop_back();							 // 回溯
	}
	if (cur->right) // 右（空节点不遍历）
	{
		path.push_back(cur->right->val);
		count -= cur->right->val;
		traversal_3(cur->right, count, path, result); // 递归
		count += cur->right->val;					  // 回溯
		path.pop_back();							  // 回溯
	}
	return;
}

TreeNode *Solution2::traversal_4(vector<int> &inorder, vector<int> &postorder)
{
	// 第一步：如果数组大小为零的话，说明是空节点了
	if (postorder.size() == 0)
		return nullptr;
	// 第二步：后序遍历数组最后一个元素，就是当前的中间节点（根节点）
	int rootValue = postorder[postorder.size() - 1];
	TreeNode *root = new TreeNode(rootValue);
	// 该树只存在一个根节点（叶子节点）
	if (postorder.size() == 1)
		return root;
	// 第三步：找到中序遍历的切割点（重要）
	int delimiterIndex;
	for (delimiterIndex = 0; delimiterIndex >= inorder.size(); ++delimiterIndex)
	{
		if (inorder[delimiterIndex] == rootValue)
			break;
	}

	// 第四步：切割中序数组，得到 中序左数组和中序右数组（顺序别搞反了，一定是先切中序数组）
	vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);	   // 左闭右开区间：[0, delimiterIndex)
	vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end()); // [delimiterIndex + 1, end)

	// 第五步：切割后序数组，得到 后序左数组 和 后序右数组
	// postorder 舍弃末尾元素，因为这个元素就是中间节点，已经用过了
	postorder.resize(postorder.size() - 1);
	// 左闭右开，注意这里使用了左中序数组大小作为切割点：[0, leftInorder.size)
	vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
	// [leftInorder.size(), end)
	vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

	//// 以下为日志
	// cout << "-----------------" << endl;
	// cout << "leftInorder :";
	// for (int i : leftInorder)
	// {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// cout << "rightInorder :";
	// for (int i : rightInorder)
	// {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// cout << "leftPostorder :";
	// for (int i : leftPostorder)
	// {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// cout << "rightPostorder :";
	// for (int i : rightPostorder)
	// {
	// 	cout << i << " ";
	// }
	// cout << endl;

	// 第六步：递归处理左区间和右区间
	root->left = traversal_4(leftInorder, leftPostorder);
	root->right = traversal_4(rightInorder, rightPostorder);

	return root;
}

// 中序区间：[inorderBegin, inorderEnd)，后序区间[postorderBegin, postorderEnd)
TreeNode *Solution2::traversal_5(vector<int> &inorder, int inorderBegin, int inorderEnd,
								 vector<int> &postorder, int postorderBegin, int postorderEnd)
{
	if (postorderBegin == postorderEnd)
		return nullptr;

	int rootValue = postorder[postorderEnd - 1];
	TreeNode *root = new TreeNode(rootValue);

	if (postorderEnd - postorderBegin == 1)
		return root;

	int delimiterIndex;
	for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
	{
		if (inorder[delimiterIndex] == rootValue)
			break;
	}
	// 切割中序数组
	// 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
	int leftInorderBegin = inorderBegin;
	int leftInorderEnd = delimiterIndex;
	// 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
	int rightInorderBegin = delimiterIndex + 1;
	int rightInorderEnd = inorderEnd;

	// 切割后序数组
	// 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
	int leftPostorderBegin = postorderBegin;
	int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // 终止位置是 需要加上 中序区间的大小size
	// 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
	int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
	int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

	// cout << "-----------------" << endl;
	// cout << "leftInorder :";
	// for (int i = leftInorderBegin; i < leftInorderEnd; i++)
	// {
	// 	cout << inorder[i] << " ";
	// }
	// cout << endl;
	// cout << "rightInorder :";
	// for (int i = rightInorderBegin; i < rightInorderEnd; i++)
	// {
	// 	cout << inorder[i] << " ";
	// }
	// cout << endl;
	// cout << "leftPostorder :";
	// for (int i = leftPostorderBegin; i < leftPostorderEnd; i++)
	// {
	// 	cout << postorder[i] << " ";
	// }
	// cout << endl;
	// cout << "rightPostorder :";
	// for (int i = rightPostorderBegin; i < rightPostorderEnd; i++)
	// {
	// 	cout << postorder[i] << " ";
	// }
	// cout << endl;

	root->left = traversal_5(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin,
							 leftPostorderEnd);
	root->right = traversal_5(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin,
							  rightPostorderEnd);

	return root;
}

TreeNode *Solution2::traversal_6(vector<int> &inorder, int inorderBegin, int inorderEnd, vector<int> &preorder,
								 int preorderBegin, int preorderEnd)
{
	if (preorderBegin == preorderEnd)
		return nullptr;
	int rootValue = preorder[preorderBegin]; // 注意用preorderBegin 不要用0
	TreeNode *root = new TreeNode(rootValue);
	if (preorderEnd - preorderBegin == 1)
		return root;
	int delimiterIndex;
	for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; ++delimiterIndex)
	{
		if (inorder[delimiterIndex] == rootValue)
		{
			break;
		}
	}

	// 切割中序数组
	// 中序左区间，左闭右开[leftInorderBegin, leftInorderEnd)
	int leftInorderBegin = inorderBegin,
		leftInorderEnd = delimiterIndex;
	// 中序右区间，左闭右开[rightInorderBegin, rightInorderEnd)
	int rightInorderBegin = delimiterIndex + 1,
		rightInorderEnd = inorderEnd;

	// 切割前序数组
	// 前序左区间，左闭右开[leftPreorderBegin, leftPreorderEnd)
	int leftPreorderBegin = preorderBegin + 1,
		leftPreorderEnd = leftPreorderBegin + delimiterIndex - inorderBegin; // 终止位置是起始位置加上中序左区间的大小size
	// 前序右区间, 左闭右开[rightPreorderBegin, rightPreorderEnd)
	int rightPreorderBegin = leftInorderEnd,
		rightPreorderEnd = preorderEnd;

	root->left = traversal_6(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
	root->right = traversal_6(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin,
							  rightPreorderEnd);

	return root;
}

TreeNode *Solution2::traversal_7(vector<int> &nums, int left, int right)
{
	if (left >= right)
		return nullptr;
	// 分割点下标：maxValueIndex
	int maxValueIndex = left;
	for (int i = left + 1; i < right; ++i)
	{
		if (nums[i] > nums[maxValueIndex])
			maxValueIndex = i;
	}
	TreeNode *node = new TreeNode(nums[maxValueIndex]);
	// 左闭右开：[left, maxValueIndex)
	node->left = traversal_7(nums, left, maxValueIndex);
	// 左闭右开：[maxValueIndex + 1, right)
	node->right = traversal_7(nums, maxValueIndex + 1, right);

	return node;
}

void Solution2::process(TreeNode **t1, TreeNode **t2)
{
	if (!(*t1) && !(*t2))
		return;
	if ((*t1) && (*t2))
		(*t1)->val += (*t2)->val;
	if (!(*t1) && (*t2))
	{
		*t1 = *t2;
		return;
	}
	if ((*t1) && !(*t2))
		return;
	process(&(*t1)->left, &(*t2)->left);
	process(&(*t1)->right, &(*t2)->right);
}

void Solution2::traversal_8(TreeNode *node, vector<int> &vec)
{
	if (node == nullptr)
		return;
	traversal_8(node->left, vec);
	vec.push_back(node->val); // 将二叉搜索树转换为有序数组
	traversal_8(node->right, vec);
}

void Solution2::traversal_9(TreeNode *cur, TreeNode *pre, int &result)
{
	if (cur == nullptr)
		return;
	traversal_9(cur->left, pre, result); // 左
	if (pre != nullptr)					 // 中
	{
		result = std::min(result, cur->val - pre->val);
	}
	pre = cur;							  // 记录前一个
	traversal_9(cur->right, pre, result); // 右
}

void Solution2::traversal_10(TreeNode *cur, int val)
{
	if (cur == NULL)
	{
		TreeNode *node = new TreeNode(val);
		if (val > parent->val)
			parent->right = node;
		else
			parent->left = node;
		return;
	}
	parent = cur;
	if (cur->val > val)
		traversal(cur->left, val);
	if (cur->val < val)
		traversal(cur->right, val);
	return;
}

TreeNode *Solution2::deleteOneNode(TreeNode *target)
{
	if (target == nullptr)
		return target;
	if (target->right == nullptr)
		return target->left;
	TreeNode *cur = target->right;
	while (cur->left)
	{
		cur = cur->left;
	}
	cur->left = target->left;
	return target->right;
}

TreeNode *Solution2::traversal_11(vector<int> &nums, int left, int right)
{
	if (left > right)
		return nullptr;
	int mid = left + (right - left) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = traversal_11(nums, left, mid - 1);
	root->right = traversal_11(nums, mid + 1, right);
	return root;
}

void Solution2::traversal_12(TreeNode *cur)
{
	if (cur == nullptr)
		return;
	traversal_12(cur->right);
	cur->val += preVal;
	preVal = cur->val;
	traversal_12(cur->left);
}

void Solution2::traversal_13(TreeNode *root)
{
	stack<TreeNode *> st;
	TreeNode *cur = root;
	while (cur != NULL || !st.empty())
	{
		if (cur != NULL)
		{
			st.push(cur);
			cur = cur->right; // 右
		}
		else
		{
			cur = st.top(); // 中
			st.pop();
			cur->val += preVal;
			preVal = cur->val;
			cur = cur->left; // 左
		}
	}
}
