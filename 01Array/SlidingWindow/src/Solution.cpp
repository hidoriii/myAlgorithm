#include "Solution.h"
#include <iostream>
#include <unordered_map>

int Solution::minSubArrayLen(int target, vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	int result = INT32_MAX;
	int sum = 0; // 滑动窗口数值之和
	int start = 0; // 滑动窗口起始位置
	int subLength = 0; // 滑动窗口的长度
	for (int end = 0; end < n; end++) {
		sum += nums[end];
		// 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
		while (sum >= target) {
			subLength = end - start + 1; // 取子序列的长度
			result = result < subLength ? result : subLength;
			sum -= nums[start++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
		}
	}
	// 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
	return result == INT32_MAX ? 0 : result;
}

int Solution::totalFruit(vector<int>& fruits)
{
	int n = fruits.size();
	if (n == 0)
		return 0;
	int ans = 0;
	int *cnts = new int[n + 10]();
	for (int i = 0, j = 0, tot = 0; i < n; i++) {
		if (++cnts[fruits[i]] == 1)
			tot++;
		while (tot > 2) 
			if (--cnts[fruits[j++]] == 0) 
				tot--;
		ans = std::max(ans, i - j + 1);
	}
	return ans;

	// Official Answer:
	/*int n = fruits.size();
	std::unordered_map<int, int> cnt;
	int left = 0, ans = 0;
	for (int right = 0; right < n; ++right) {
		++cnt[fruits[right]];
		while (cnt.size() > 2) {
			auto it = cnt.find(fruits[left]);
			--it->second;
			if (it->second == 0) {
				cnt.erase(it);
			}
			++left;
		}
		ans = std::max(ans, right - left + 1);
	}
	return ans;*/
}

string Solution::minWindow(string S, string T)
{
	vector<int> chars(128, 0);
	vector<bool> flag(128, false);
	// 先统计T中的字符情况
	for (int i = 0; i < T.size(); ++i) {
		flag[T[i]] = true;
		++chars[T[i]];
	}
	// 移动滑动窗口，不断更新统计数据
	int cnt = 0, left = 0, min_l = 0, min_size = S.size() + 1;
	for (int right = 0; right < S.size(); ++right) {
		if (flag[S[right]]) {
			if (--chars[S[right]] >= 0)
				++cnt;
			// 若目前滑动窗口已包含t中全部字符
			// 则尝试将left右移，在不影响结果的情况下获得最短子字符串
			while (cnt == T.size()) {
				if (right - left + 1 < min_size) {
					min_l = left;
					min_size = right - left + 1;
				}
				if (flag[S[left]] && ++chars[S[left]] > 0) {
					--cnt;
				}
				++left;
			}
		}
	}
	return min_size > S.size() ? "" : S.substr(min_l, min_size);
}
