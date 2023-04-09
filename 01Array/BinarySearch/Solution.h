#pragma once
#include <vector>
using std::vector;

class Solution {
public:
	int search_1(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1; // ����target������ұյ������[left, right]
		while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч�������� <=
			int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
			if (nums[middle] > target) {
				right = middle - 1; // target �������䣬����[left, middle - 1]
			}
			else if (nums[middle] < target) {
				left = middle + 1; // target �������䣬����[middle + 1, right]
			}
			else { // nums[middle] == target
				return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}
		}
		// δ�ҵ�Ŀ��ֵ
		return -1;
	}
	int search_2(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size(); // ����target������ҿ������������[left, right)
		while (left < right) { // ��Ϊleft == right��ʱ����[left, right)����Ч�Ŀռ䣬����ʹ�� <
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle; // target �������䣬��[left, middle)��
			}
			else if (nums[middle] < target) {
				left = middle + 1; // target �������䣬��[middle + 1, right)��
			}
			else { // nums[middle] == target
				return middle; // �������ҵ�Ŀ��ֵ��ֱ�ӷ����±�
			}
		}
		// δ�ҵ�Ŀ��ֵ
		return -1;
	}
	// 35.��������λ��
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
		// �ֱ��������������
		// Ŀ��ֵ����������Ԫ��֮ǰ  [0, -1]   ��ʱright = mid - 1 == -1 ,���� return right + 1;
		// Ŀ��ֵ����������ĳһ��Ԫ��  return middle;
		// Ŀ��ֵ���������е�λ�� [left, right]��return right + 1
		// Ŀ��ֵ����������Ԫ��֮������ [left, right]�� ��Ϊ���ұ����䣬���� return right + 1
		return right + 1;
	}
	// 34.�����������в���Ԫ�صĵ�һ�������һ��λ��
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int leftBorder = getLeftBorder(nums, target);
		int rightBorder = getRightBorder(nums, target);
		// ���һ��target �����鷶Χ���ұ߻�����ߣ���������{3, 4, 5}��targetΪ2��������{3, 4, 5},targetΪ6����ʱӦ�÷���{-1, -1}
		if (leftBorder == -2 || rightBorder == -2) return { -1, -1 };
		// �������target �����鷶Χ�У��������д���target����������{3,6,7},targetΪ6����ʱӦ�÷���{1, 1}
		if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };
		// �������target �����鷶Χ�У��������в�����target����������{3,6,7},targetΪ5����ʱӦ�÷���{-1, -1}
		return { -1, -1 };
	}
	// 69. x ��ƽ����
	int mySqrt(int x);
	// 367.��Ч����ȫƽ����
	bool isPerfectSquare(int num);
private:
	int getRightBorder(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int rightBorder = -2; // ��¼һ��rightBorderû�б���ֵ�����
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > target)
				right = mid - 1;
			else { // ��nums[middle] == target��ʱ�򣬸���left���������ܵõ�target���ұ߽�
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
			else { // Ѱ����߽磬��Ҫ��nums[middle] == target��ʱ�����right
				right = mid - 1;
				leftBorder = right;
			}
		}
		return leftBorder;
	}
};
