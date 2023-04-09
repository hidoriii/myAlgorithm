#pragma once
#include <vector>
using std::vector;

class Solution {
public:
	int search_1(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
		while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
			int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
			if (nums[middle] > target) {
				right = middle - 1; // target 在左区间，所以[left, middle - 1]
			}
			else if (nums[middle] < target) {
				left = middle + 1; // target 在右区间，所以[middle + 1, right]
			}
			else { // nums[middle] == target
				return middle; // 数组中找到目标值，直接返回下标
			}
		}
		// 未找到目标值
		return -1;
	}
	int search_2(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
		while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle; // target 在左区间，在[left, middle)中
			}
			else if (nums[middle] < target) {
				left = middle + 1; // target 在右区间，在[middle + 1, right)中
			}
			else { // nums[middle] == target
				return middle; // 数组中找到目标值，直接返回下标
			}
		}
		// 未找到目标值
		return -1;
	}
	// 35.搜索插入位置
	int searchInsert(vector<int>& nums, int target)
	{
		int n = nums.size();
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > target) right = mid - 1;
			else if (nums[mid] < target) left = mid + 1;
			else return mid;
		}
		// 分别处理如下四种情况
		// 目标值在数组所有元素之前  [0, -1]   此时right = mid - 1 == -1 ,所以 return right + 1;
		// 目标值等于数组中某一个元素  return middle;
		// 目标值插入数组中的位置 [left, right]，return right + 1
		// 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
		return right + 1;
	}
	// 34.在排序数组中查找元素的第一个和最后一个位置
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int leftBorder = getLeftBorder(nums, target);
		int rightBorder = getRightBorder(nums, target);
		// 情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
		if (leftBorder == -2 || rightBorder == -2) return { -1, -1 };
		// 情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}
		if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };
		// 情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
		return { -1, -1 };
	}
	// 69. x 的平方根
	int mySqrt(int x);
	// 367.有效的完全平方数
	bool isPerfectSquare(int num);
private:
	int getRightBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > target)
				right = mid - 1;
			else { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
				left = mid + 1;
				rightBorder = left;
			}
		}
		//		1 2 3 3 4 4 5 6
		//left	            ^
		//mid               ^
		return rightBorder;
	}
	int getLeftBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int leftBorder = -2;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else { // 寻找左边界，就要在nums[middle] == target的时候更新right
				right = mid - 1;
				leftBorder = right;
			}
		}
		return leftBorder;
	}
};
