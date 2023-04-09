#pragma once
#include <vector>
using std::vector;

class Solution
{
public:
	// 704. ���ֲ��� https://leetcode.cn/problems/binary-search/
	int search_1(vector<int> &nums, int target);
	int search_2(vector<int> &nums, int target);
	// 35.��������λ�� https://leetcode.cn/problems/search-insert-position/
	int searchInsert(vector<int> &nums, int target);
	// 34.�����������в���Ԫ�صĵ�һ�������һ��λ�� https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
	vector<int> searchRange(vector<int> &nums, int target);
	// 69. x��ƽ���� https://leetcode.cn/problems/sqrtx/
	int mySqrt(int x);
	// 367.��Ч����ȫƽ���� https://leetcode.cn/problems/valid-perfect-square/
	bool isPerfectSquare(int num);

private:
	int getRightBorder(vector<int> &nums, int target);
	int getLeftBorder(vector<int> &nums, int target);
};
