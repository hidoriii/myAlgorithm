#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
	// 209.������С�������� https://leetcode.cn/problems/minimum-size-subarray-sum/
	int minSubArrayLen(int target, vector<int>& nums);
	// 904.ˮ������ https://leetcode.cn/problems/fruit-into-baskets/
	int totalFruit(vector<int>& fruits);
	// 76.��С�����Ӵ�(opens new window) https://leetcode.cn/problems/minimum-window-substring/
	string minWindow(string S, string T);
};

