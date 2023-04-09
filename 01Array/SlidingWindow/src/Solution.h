#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
	// 209.长度最小的子数组 https://leetcode.cn/problems/minimum-size-subarray-sum/
	int minSubArrayLen(int target, vector<int>& nums);
	// 904.水果成篮 https://leetcode.cn/problems/fruit-into-baskets/
	int totalFruit(vector<int>& fruits);
	// 76.最小覆盖子串(opens new window) https://leetcode.cn/problems/minimum-window-substring/
	string minWindow(string S, string T);
};

