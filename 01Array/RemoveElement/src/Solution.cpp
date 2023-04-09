#include <iostream>
#include "Solution.h"

int Solution::removeElement(vector<int>& nums, int val)
{
	int slow = 0;
	for (int fast = 0; fast < nums.size(); fast++)
		if (nums[fast] != val)
			nums[slow++] = nums[fast];
	return slow;
}

int Solution::removeDuplicates(vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	int slow = 0, fast = 1;
	while (fast < n) {
		if (nums[slow] != nums[fast]) {
			if (fast - slow > 1) { // �Ż���ֻ�е� fast - slow > 1ʱ����ȷʵ�����ظ���Ԫ��ʱ�Ž��и���
				nums[slow + 1] = nums[fast];
			}
			slow++; // �Ż���slow++Ҫ�������ڲ�if�����档��ζ�Ų�����ʱ��������ĳ�����Ҫ����һ�Ρ�
		}
		fast++;
	}
	return slow + 1;
}

void Solution::moveZeroes(vector<int>& nums)
{
	int n = nums.size();
	int fast = 0, slow = 0;
	while (fast < n) {
		if (nums[fast] != 0)
			nums[slow++] = nums[fast];
		fast++;
	}
	while (slow < n)
		nums[slow++] = 0;

	// Answer:
	/*int n = nums.size();
	int left = 0, right = 0;
	while (right < n) {
		if (nums[right]) {
			std::swap(nums[left], nums[right]);
			left++;
		}
		right++;
	}*/
}

bool Solution::backspaceCompare(string s, string t)
{
	int i = s.size() - 1, j = t.size() - 1;
	int skipS = 0, skipT = 0;
	while (i >= 0 || j >= 0) {
		while (i >= 0) {
			if (s[i] == '#')
				skipS++, i--;
			else if (skipS > 0)
				skipS--, i--;
			else
				break;
		}
		while (j >= 0) {
			if (t[j] == '#')
				skipT++, j--;
			else if (skipT > 0)
				skipT--, j--;
			else
				break;
		}
		if (i >= 0 && j >= 0) {
			if (s[i] != t[j])
				return false;
		}
		else {
			if (i >= 0 || j >= 0)
				return false;
		}
		i--, j--;
	}
	return true;
}

vector<int> Solution::sortedSquares(vector<int>& nums)
{
	int n = nums.size();
	vector<int> ans(n);
	for (int left = 0, right = n - 1, pos = n - 1; left <= right; ) {
		if (nums[left] * nums[left] > nums[right] * nums[right]) {
			ans[pos--] = nums[left] * nums[left];
			++left;
		}
		else {
			ans[pos--] = nums[right] * nums[right];
			--right;
		}
	}
	return ans;
}