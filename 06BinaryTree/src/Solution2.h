#pragma once

#include "Solution.h"

class Solution2
{
public:
	// 404. 左叶子之和 https://leetcode.cn/problems/sum-of-left-leaves/
	int sumOfLeftLeaves(TreeNode *root);   // 递归（后序）
	int sumOfLeftLeaves_2(TreeNode *root); // 迭代
	// 513. 找树左下角的值 https://leetcode.cn/problems/find-bottom-left-tree-value/
	int findBottomLeftValue(TreeNode *root);   // BFS
	int findBottomLeftValue_2(TreeNode *root); // DFS（前序）
	// 112. 路径总和 https://leetcode.cn/problems/path-sum/
	bool hasPathSum(TreeNode *root, int targetSum);	  // 递归 + 回溯
	bool hasPathSum_2(TreeNode *root, int targetSum); // 迭代
	// 113. 路径总和II https://leetcode.cn/problems/path-sum-ii/
	vector<vector<int>> pathSum(TreeNode *root, int targetSum); // DFS（本题不适合BFS）
	// 106. 从中序与后序遍历序列构造二叉树 https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);
	// 105. 从前序与中序遍历序列构造二叉树 https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
	TreeNode *buildTreeII(vector<int> &preorder, vector<int> &inorder);
	// 654. 最大二叉树 https://leetcode.cn/problems/maximum-binary-tree/
	TreeNode *constructMaximumBinaryTree(vector<int> &nums);
	TreeNode *constructMaximumBinaryTree_2(vector<int> &nums);
	// 617. 合并二叉树 https://leetcode.cn/problems/merge-two-binary-trees/
	TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2);	  // 递归（前序）
	TreeNode *mergeTrees_2(TreeNode *root1, TreeNode *root2); // 迭代
	TreeNode *mergeTrees_3(TreeNode *root1, TreeNode *root2); // 指针
	// 700. 二叉搜索树中的搜索 https://leetcode.cn/problems/search-in-a-binary-search-tree/
	TreeNode *searchBST(TreeNode *root, int val);	// 递归
	TreeNode *searchBST_2(TreeNode *root, int val); // 迭代
	// 98. 验证二叉搜索树 https://leetcode.cn/problems/validate-binary-search-tree/
	bool isValidBST(TreeNode *root);
	long long maxVal = LONG_MIN;
	bool isValidBST_2(TreeNode *root);
	bool isValidBST_3(TreeNode *root);
	bool isValidBST_4(TreeNode *root); // 迭代
	// 530. 二叉搜索树的最小绝对差 https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
	int getMinimumDifference(TreeNode *root);	// 中序
	int getMinimumDifference_2(TreeNode *root); // 中序
	// 501.二叉搜索树中的众数 https://leetcode.cn/problems/find-mode-in-binary-search-tree/
	void update(int x);					  // 扫描到一个新的元素并更新变量 base, count, maxCount, answer
	void dfs(TreeNode *o);				  // 中序遍历扫描每一个元素
	vector<int> findMode(TreeNode *root); // 递归
	void searchBST_2(TreeNode *cur);
	vector<int> findMode_2(TreeNode *root);		 // 递归
	vector<int> findMode_3(TreeNode *root);		 // 迭代
	vector<int> findMode_Morris(TreeNode *root); // Morris遍历

	// 236. 二叉树的最近公共祖先 https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
	// 235. 二叉搜索树的最近公共祖先 https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
	TreeNode *lowestCommonAncestor_BST(TreeNode *root, TreeNode *p, TreeNode *q);	// 递归
	TreeNode *lowestCommonAncestor_BST_2(TreeNode *root, TreeNode *p, TreeNode *q); // 迭代
	// 701. 二叉搜索树中的插入操作 https://leetcode.cn/problems/insert-into-a-binary-search-tree/
	TreeNode *insertIntoBST(TreeNode *root, int val);	// 递归（有返回值）
	TreeNode *insertIntoBST_2(TreeNode *root, int val); // 递归（无返回值）
	TreeNode *insertIntoBST_3(TreeNode *root, int val); // 迭代
	// 450. 删除二叉搜索树中的节点 https://leetcode.cn/problems/delete-node-in-a-bst/
	TreeNode *deleteNode(TreeNode *root, int key);	 // 递归
	TreeNode *deleteNode_2(TreeNode *root, int key); // 迭代
	// 669. 修剪二叉搜索树 https://leetcode.cn/problems/trim-a-binary-search-tree/
	TreeNode *trimBST(TreeNode *root, int low, int high);	// 递归
	TreeNode *trimBST_2(TreeNode *root, int low, int high); // 迭代
	// 108. 将有序数组转换为二叉搜索树 https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
	TreeNode *sortedArrayToBST(vector<int> &nums);	 // 递归
	TreeNode *sortedArrayToBST_2(vector<int> &nums); // 迭代
	// 538. 把二叉搜索树转换为累加树 https://leetcode.cn/problems/convert-bst-to-greater-tree/
	TreeNode *convertBST(TreeNode *root);	// 递归
	TreeNode *convertBST_2(TreeNode *root); // 迭代

private:
	int max_depth = INT_MIN; // 记录最大深度
	int result = 0;			 // 记录最大深度最左节点的数值
	TreeNode *pre = nullptr; // 用来记录前一个节点

	int base,			// 记录当前位置的数字
		count = 0,		// 记录当前数组的重复次数
		maxCount = 0;	// 维护已经扫描过的数当中出现最多的那个数字的出现次数
	vector<int> answer; // 记录出现的众数

	TreeNode *parent; // 记录遍历节点的父节点

	void traversal(TreeNode *node, int depth);

	bool traversal_2(TreeNode *node, int count);

	void traversal_3(TreeNode *cur, int count, vector<int> &path, vector<vector<int>> &result);

	TreeNode *traversal_4(vector<int> &inorder, vector<int> &postorder);
	TreeNode *traversal_5(vector<int> &inorder, int inorderBegin, int inorderEnd,
						  vector<int> &postorder, int postorderBegin, int postorderEnd);

	TreeNode *traversal_6(vector<int> &inorder, int inorderBegin, int inorderEnd,
						  vector<int> &preorder, int preorderBegin, int preorderEnd);

	TreeNode *traversal_7(vector<int> &nums, int left, int right);

	void process(TreeNode **t1, TreeNode **t2);

	/**
	 * \brief 将二叉搜索树转换成一个有序数组
	 * \param node
	 * \param vec
	 */
	void traversal_8(TreeNode *node, vector<int> &vec);

	void traversal_9(TreeNode *cur, TreeNode *pre, int &result);

	void traversal_10(TreeNode *cur, int val);

	/**
	 * @brief 将目标节点（删除节点）的左子树放到 目标节点的右子树的最左面节点的左孩子位置上
	 * 		  并返回目标节点右孩子为新的根节点
	 *		  是动画里模拟的过程
	 *
	 * @param target
	 * @return TreeNode*
	 */
	TreeNode *deleteOneNode(TreeNode *target);
	/**
	 * @brief 用 nums数组构造 平衡 二叉搜索树  注意是：左闭右闭区间 [left, right]
	 *
	 * @param nums
	 * @param left
	 * @param right
	 * @return TreeNode* 返回构造好的（平衡）二叉搜索树的根节点
	 */
	TreeNode *traversal_11(vector<int> &nums, int left, int right);

	int preVal = 0; // 记录前一个节点的数值
	/**
	 * @brief 通过 右 中 左 （反中序）顺序 构造 一个二叉搜索树
	 *
	 * @param cur
	 */
	void traversal_12(TreeNode *cur);

	void traversal_13(TreeNode *root);
};
