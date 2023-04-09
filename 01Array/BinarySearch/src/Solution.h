#pragma once
#include <vector>
using std::vector;

class Solution
{
public:
	// 704. 二分查找 https://leetcode.cn/problems/binary-search/
	int search_1(vector<int> &nums, int target);
	int search_2(vector<int> &nums, int target);
	// 35.搜索插入位置 https://leetcode.cn/problems/search-insert-position/
	int searchInsert(vector<int> &nums, int target);
	// 34.在排序数组中查找元素的第一个和最后一个位置 https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
	vector<int> searchRange(vector<int> &nums, int target);
	// 69. x的平方根 https://leetcode.cn/problems/sqrtx/
	int mySqrt(int x);
	// 367.有效的完全平方数 https://leetcode.cn/problems/valid-perfect-square/
	bool isPerfectSquare(int num);

private:
	int getRightBorder(vector<int> &nums, int target);
	int getLeftBorder(vector<int> &nums, int target);
};
