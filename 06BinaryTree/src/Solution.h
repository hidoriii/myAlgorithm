#pragma
#include <cstdio>
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;

struct TreeNode;
class NNode;
class Node;

class Solution
{
public:
	// 二叉树的深度遍历算法 (DFS)：
	// 144. 二叉树的前序遍历 https://leetcode.cn/problems/binary-tree-preorder-traversal/
	vector<int> preorderTraversal(TreeNode* root); // 递归法
	vector<int> preorderTraversal_2(TreeNode* root); // 迭代法
	vector<int> preorderTraversal_3(TreeNode* root); // 统一迭代法
	// 94. 二叉树的中序遍历 https://leetcode.cn/problems/binary-tree-inorder-traversal/
	vector<int> inorderTraversal(TreeNode* root); // 递归法
	vector<int> inorderTraversal_2(TreeNode* root); // 迭代法
	vector<int> inorderTraversal_3(TreeNode* root); // 统一迭代法
	// 145. 二叉树的后序遍历 https://leetcode.cn/problems/binary-tree-postorder-traversal/
	vector<int> postorderTraversal(TreeNode* root); // 递n归法
	vector<int> postorderTraversal_2(TreeNode* root); // 迭代法
	vector<int> postorderTraversal_3(TreeNode* root); // 统一迭代法

	// 二叉树的广度遍历算法 (BFS)：
	// 102. 二叉树的层序遍历 https://leetcode.cn/problems/binary-tree-level-order-traversal/
	vector<vector<int>> levelOrder(TreeNode* root); // 队列
	vector<vector<int>> levelOrder_2(TreeNode* root); // 递归法
	// 107. 二叉树的层次遍历II https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
	vector<vector<int>> levelOrderBottom(TreeNode* root);
	// 199. 二叉树的右视图 https://leetcode.cn/problems/binary-tree-right-side-view/
	vector<int> rightSideView(TreeNode* root);
	vector<int> rightSideView_2(TreeNode* root); // 递归法
	// 637. 二叉树的层平均值 https://leetcode.cn/problems/average-of-levels-in-binary-tree/
	vector<double> averageOfLevels(TreeNode* root);
	// 429. N叉树的层序遍历 https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
	vector<vector<int>> levelOrderByNTree(NNode* root);
	// 515. 在每个树行中找最大值 https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
	vector<int> largestValues(TreeNode* root);
	// 116. 填充每个节点的下一个右侧节点指针 https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
	Node* connect(Node* root);
	// 117. 填充每个节点的下一个右侧节点指针II https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
	Node* connect_II(Node* root);
	// 104. 二叉树的最大深度 https://leetcode.cn/problems/maximum-depth-of-binary-tree/
	int maxDepth(TreeNode* root);
	// 111. 二叉树的最小深度 https://leetcode.cn/problems/minimum-depth-of-binary-tree/
	int minDepth(TreeNode* root); // BFS
	int minDepth_2(TreeNode* root); // DFS

	// 二叉树的morris遍历算法（了解即可） 该算法可以将空间复杂度降为O(1)
	vector<int> morrisPre(TreeNode* root);
	vector<int> morrisIn(TreeNode* root);
	vector<int> morrisPos(TreeNode* root);

	// 226. 翻转二叉树 https://leetcode.cn/problems/invert-binary-tree/
	TreeNode* invertTree(TreeNode* root); // 递归法（前序遍历）
	TreeNode* invertTree_2(TreeNode* root); // 迭代法（前序遍历）
	TreeNode* invertTree_3(TreeNode* root); // 统一迭代法（前序遍历）
	TreeNode* invertTree_4(TreeNode* root); // BFS（层序遍历）
	TreeNode* invertTree_5(TreeNode* root); // 递归法（中序遍历）
	TreeNode* invertTree_6(TreeNode* root); // 统一迭代法（中序遍历）

	// 101. 对称二叉树 https://leetcode.cn/problems/symmetric-tree/
	bool isSymmetric(TreeNode* root); // 递归法
	bool isSymmetric_2(TreeNode* root); // 迭代法（队列）
	bool isSymmetric_3(TreeNode* root); // 迭代法（栈）
	// 100. 相同的树 https://leetcode.cn/problems/same-tree/
	bool isSameTree(TreeNode* p, TreeNode* q); // DFS
	bool isSameTree_2(TreeNode* p, TreeNode* q); // BFS
	// 572. 另一个树的子树 https://leetcode.cn/problems/subtree-of-another-tree/
	bool isSubtree(TreeNode* root, TreeNode* subRoot); // DFS暴力解法 T(n) = O(|s| * |t|)
	bool isSubtree_2(TreeNode* root, TreeNode* subRoot); // DFS + KMP T(n) = O(|s| + |t|)

	// 以下是树哈希解法
private:
	static constexpr int MAX_N = 1000 + 5;
	static constexpr int MOD = static_cast<int>(1E9) + 7;
	bool vis[MAX_N];
	int p[MAX_N], tot;
	void getPrime();

	struct Status
	{
		int f, s; // f为哈希值，s为子树大小
		Status(int f_ = 0, int s_ = 0) : f(f_), s(s_)
		{
		}
	};

	unordered_map<TreeNode*, Status> hS, hT;
	void dfs_hash(TreeNode* o, unordered_map<TreeNode*, Status>& h);

public:
	bool isSubtree_3(TreeNode* root, TreeNode* subRoot); // 树哈希

public:
	// 再探二叉树的最大深度：
	int maxDepthByPos(TreeNode* root); // 递归法
	int maxDepthByPre(TreeNode* root);
	// 559. n叉树的最大深度
	int maxDepthInNTree(NNode* root); // 递归法
	int maxDepthInNTree_2(NNode* root); // 迭代法
	// 再探二叉树的最小深度：
	int minDepthByPos(TreeNode* root); // DFS（后序遍历）
	int minDepthByPre(TreeNode* root); // DFS（前序遍历）
	// 222. 完全二叉树的节点个数 https://leetcode.cn/problems/count-complete-tree-nodes/
	int countNodes(TreeNode* root); // DFS（后序遍历）
	int countNodes_2(TreeNode* root); // BFS
	int countNodes_3(TreeNode* root); // 递归法
	// 110. 平衡二叉树 https://leetcode.cn/problems/balanced-binary-tree/
	bool isBalanced(TreeNode* root); // 递归
	bool isBalanced_2(TreeNode* root); // 迭代

private:
	int result;


	void preorder_traversal(TreeNode* cur, vector<int>& vec); // 前序遍历
	void inorder_traversal(TreeNode* cur, vector<int>& vec); // 中序遍历
	void postorder_traversal(TreeNode* cur, vector<int>& vec); // 后序遍历
	void order(TreeNode* cur, vector<vector<int>>& ans, int depth); // 层序遍历
	void rightSideViewOrder(TreeNode* cur, vector<int>& ans, int depth);

	// 以下两个函数均用于 morris后序遍历
	void dealEdge(TreeNode* node, vector<int>& result);
	TreeNode* reverseEdge(TreeNode* node);

	/**
	 * @brief 用于判断一棵二叉树是否是对称的递归代码
	 * @author ray
	 * @param left 左侧结点
	 * @param right 右侧结点
	 * @return true 对称
	 * @return false 不对称
	 */
	bool compare(TreeNode* left, TreeNode* right);


	// 以下两个工具函数用于 isSubtree（DFS暴力解法）
	bool check(TreeNode* o, TreeNode* t);
	bool dfs(TreeNode* o, TreeNode* t);

	// 以下三个函数均用于 isSubtree_2（DFS + KMP解法）
	void getMaxElement(TreeNode* node, int& maxElement);
	void getDfsOrder(TreeNode* node, vector<int>& tar, int& lNull, int& rNull);
	bool kmp(vector<int>& sOrder, vector<int>& tOrder);

	int getMaxDepthByPost(TreeNode* node);

	void getMaxDepthByPre(TreeNode* node, int depth);

	int getMinDepthByPos(TreeNode* node);

	void getMinDepthByPre(TreeNode* node, int depth);

	int getNodesNumByPos(TreeNode* node);

	int getHeightByPos(TreeNode* node);

	int getMaxDepthByStack(TreeNode* node);
};

// 不同二叉树的定义：

/**
 * @brief 普通二叉树
 *
 */
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr)
	{
	}

	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}

	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r)
	{
	}
};

/**
 * @brief N叉数
 *
 */

class NNode
{
public:
	int val;
	vector<NNode*> children;

	NNode()
	{
	}

	NNode(int _val) : val(_val)
	{
	}

	NNode(int _val, vector<NNode*> _children) : val(_val), children(_children)
	{
	}
};

/**
 * @brief 带next的二叉树
 *
 */
class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(nullptr), right(nullptr), next(nullptr)
	{
	}

	Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr)
	{
	}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next)
	{
	}
};
