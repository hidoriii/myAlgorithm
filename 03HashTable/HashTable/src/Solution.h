#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
	// 242.有效的字母异位词 https://leetcode.cn/problems/valid-anagram/
	bool isAnagram(string s, string t);	  // unordered_map
	bool isAnagram_2(string s, string t); // 数组
	// 49.字母异位词分组 https://leetcode.cn/problems/group-anagrams/
	vector<vector<string>> groupAnagrams(vector<string> &strs);	  // unordered_map
	vector<vector<string>> groupAnagrams_2(vector<string> &strs); // unordered_map
	// 438.找到字符串中所有字母异位词 https://leetcode.cn/problems/find-all-anagrams-in-a-string/
	vector<int> findAnagrams(string s, string p); // vector（数组）
	// 349. 两个数组的交集 https://leetcode.cn/problems/intersection-of-two-arrays/
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2);	// unordered_set
	vector<int> intersection_2(vector<int> &nums1, vector<int> &nums2); // 数组
	// 350.两个数组的交集 II https://leetcode.cn/problems/intersection-of-two-arrays-ii/
	vector<int> intersect(vector<int> &nums1, vector<int> &nums2); // unordered_map
	// 202. 快乐数 https://leetcode.cn/problems/happy-number/
	bool isHappy(int n); // unordered_set
	// 1. 两数之和 https://leetcode.cn/problems/two-sum/
	vector<int> twoSum(vector<int> &nums, int target); // unordered_map
	// 454. 四数相加II https://leetcode.cn/problems/4sum-ii/
	int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4); // unordered_map
	// 383. 赎金信 https://leetcode.cn/problems/ransom-note/
	bool canConstruct(string ransomNote, string magazine);	 // unordered_map
	bool canConstruct_2(string ransomNote, string magazine); // 数组
	// 15. 三数之和 https://leetcode.cn/problems/3sum/
	vector<vector<int>> threeSum(vector<int> &nums);   // 哈希表
	vector<vector<int>> threeSum_2(vector<int> &nums); // 双指针
	// 18. 四数之和 https://leetcode.cn/problems/4sum/
	vector<vector<int>> fourSum(vector<int> &nums, int target); // 双指针

private:
	int getIndex(int n);
};