#pragma once
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
	// 27. �Ƴ�Ԫ�� https://leetcode.cn/problems/remove-element/
	int removeElement(vector<int>& nums, int val);
	// 26.ɾ�����������е��ظ��� https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
	int removeDuplicates(vector<int>& nums);
	// 283.�ƶ��� https://leetcode.cn/problems/move-zeroes/
	void moveZeroes(vector<int>& nums);
	// 844.�ȽϺ��˸���ַ��� https://leetcode.cn/problems/backspace-string-compare/
	bool backspaceCompare(string s, string t);
	// 977.���������ƽ�� https://leetcode.cn/problems/squares-of-a-sorted-array/
	vector<int> sortedSquares(vector<int>& nums);
};