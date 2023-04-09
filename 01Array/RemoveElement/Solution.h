#pragma once
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
	// 27. 移除元素 https://leetcode.cn/problems/remove-element/
	int removeElement(vector<int>& nums, int val);
	// 26.删除排序数组中的重复项 https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
	int removeDuplicates(vector<int>& nums);
	// 283.移动零 https://leetcode.cn/problems/move-zeroes/
	void moveZeroes(vector<int>& nums);
	// 844.比较含退格的字符串 https://leetcode.cn/problems/backspace-string-compare/
	bool backspaceCompare(string s, string t);
	// 977.有序数组的平方 https://leetcode.cn/problems/squares-of-a-sorted-array/
	vector<int> sortedSquares(vector<int>& nums);
};