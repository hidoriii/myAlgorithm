#include "Solution.h"
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <array>
#include <unordered_set>
using std::unordered_map;
using std::unordered_set;

bool Solution::isAnagram(string s, string t)
{
	int n = s.size(), sizeT = t.size();
	if (n != sizeT)
		return false;
	std::unordered_map<char, int> hash;
	for (int i = 0; i < n; ++i)
	{
		++hash[s[i]];
	}
	for (int i = 0; i < n; ++i)
	{
		--hash[t[i]];
	}
	for (auto it = hash.begin(); it != hash.end(); ++it)
	{
		if (it->second != 0)
			return false;
	}
	return true;
}

bool Solution::isAnagram_2(string s, string t)
{
	int n = s.size(), sizeT = t.size();
	if (n != sizeT)
		return false;
	int record[26] = {0};
	for (int i = 0; i < n; ++i)
	{
		++record[s[i] - 'a'];
	}
	for (int i = 0; i < n; ++i)
	{
		--record[t[i] - 'a'];
	}
	for (int i = 0; i < 26; ++i)
	{
		if (record[i] != 0)
			return false;
	}
	return true;
}

vector<vector<string>> Solution::groupAnagrams(vector<string> &strs)
{
	std::unordered_map<string, vector<string>> mp;
	for (auto &s : strs)
	{
		string key = s;
		std::sort(key.begin(), key.end());
		mp[key].emplace_back(s);
	}
	vector<vector<string>> ans;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		ans.emplace_back(it->second);
	}
	return ans;
}

vector<vector<string>> Solution::groupAnagrams_2(vector<string> &strs)
{
	// 自定义对 array<int, 26> 类型的哈希函数
	auto arrayHash = [fn = std::hash<int>{}](const std::array<int, 26> &arr) -> size_t
	{
		return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num)
							   { return (acc << 1) ^ fn(num); });
	};

	std::unordered_map<std::array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
	for (string &str : strs)
	{
		std::array<int, 26> counts{};
		int length = str.length();
		for (int i = 0; i < length; ++i)
		{
			counts[str[i] - 'a']++;
		}
		mp[counts].emplace_back(str);
	}
	vector<vector<string>> ans;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		ans.emplace_back(it->second);
	}
	return ans;
}

vector<int> Solution::findAnagrams(string s, string p)
{
	int sLen = s.size(), pLen = p.size();
	if (sLen < pLen)
		return {};
	vector<int> ans;
	vector<int> sCount(26);
	vector<int> pCount(26);
	for (int i = 0; i < pLen; ++i)
	{
		++sCount[s[i] - 'a'];
		++pCount[p[i] - 'a'];
	}
	if (sCount == pCount)
	{
		ans.emplace_back(0);
	}

	for (int i = 0; i < sLen - pLen; ++i)
	{
		--sCount[s[i] - 'a'];
		++sCount[s[i + pLen] - 'a'];
		if (sCount == pCount)
		{
			ans.emplace_back(i + 1);
		}
	}
	return ans;
}

vector<int> Solution::intersection(vector<int> &nums1, vector<int> &nums2)
{
	unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
	unordered_set<int> nums_set(nums1.begin(), nums1.end());
	for (int num : nums2)
	{
		// 发现nums2的元素 在nums_set里又出现过
		if (nums_set.find(num) != nums_set.end())
		{
			result_set.insert(num);
		}
	}
	return vector<int>(result_set.begin(), result_set.end());
}

vector<int> Solution::intersection_2(vector<int> &nums1, vector<int> &nums2)
{
	unordered_set<int> result_set;
	int hash[1001] = {0};
	for (int num : nums1)
	{
		hash[num] = 1;
	}
	for (int num : nums2)
	{
		if (hash[num] == 1)
			result_set.insert(num);
	}
	return vector<int>(result_set.begin(), result_set.end());
}

vector<int> Solution::intersect(vector<int> &nums1, vector<int> &nums2)
{
	if (nums1.size() > nums2.size())
		return intersect(nums2, nums1);
	unordered_map<int, int> hashmap;
	vector<int> ans;
	for (int num : nums1)
	{
		++hashmap[num];
	}
	for (int num : nums2)
	{
		if (hashmap[num]) // 如果hashmap中num对应的值不为0
		{
			--hashmap[num];
			ans.push_back(num);
		}
	}
	return ans;
}

bool Solution::isHappy(int n)
{
	unordered_set<int> seen;
	while (n != 1 && seen.find(n) == seen.end())
	{
		seen.insert(n);
		n = getIndex(n);
	}
	return n == 1;
}

vector<int> Solution::twoSum(vector<int> &nums, int target)
{
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		auto iter = m.find(target - nums[i]);
		if (iter != m.end())
		{
			return {iter->second, i};
		}
		m.insert({nums[i], i});
	}
	return {};
}

int Solution::fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
	unordered_map<int, int> umap; // key:a+b的数值，value:a+b数值出现的次数
	// 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
	for (int a : nums1)
	{
		for (int b : nums2)
		{
			++umap[a + b];
		}
	}
	int count = 0; // 统计a+b+c+d = 0 出现的次数
	// 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来
	for (int c : nums3)
	{
		for (int d : nums4)
		{
			if (umap.find(0 - (c + d)) != umap.end()) // 如果找到与umap中key相反的数，count就+=其对应的value(出现的次数)
			{
				count += umap[0 - (c + d)];
			}
		}
	}
	return count;
}

bool Solution::canConstruct(string ransomNote, string magazine)
{
	if (ransomNote.size() > magazine.size())
		return false;
	unordered_map<char, int> m;
	for (auto c : magazine)
		++m[c];
	for (auto c : ransomNote)
	{
		auto iter = m.find(c);
		if (iter == m.end() || iter->second-- == 0)
			return false;
	}
	return true;
}

bool Solution::canConstruct_2(string ransomNote, string magazine)
{
	int record[26] = {0};
	if (ransomNote.size() > magazine.size())
		return false;
	for (auto c : magazine)
		++record[c - 'a'];
	for (auto c : ransomNote)
		if (--record[c - 'a'] < 0)
			return false;
	return true;
}

vector<vector<int>> Solution::threeSum(vector<int> &nums)
{
	vector<vector<int>> ans;
	std::sort(nums.begin(), nums.end());
	// 找出a + b + c = 0
	// a = nums[i], b = nums[j], c = -(a + b)
	for (int i = 0; i < nums.size(); i++)
	{
		// 排序之后如果第一个元素已经大于零，那么就不可能凑成三元组
		if (nums[i] > 0)
		{
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1])
		{ // 三元组元素a去重
			continue;
		}
		unordered_set<int> set;
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
			{ // 三元组元素b去重
				continue;
			}
			int c = 0 - (nums[i] + nums[j]);
			if (set.find(c) != set.end())
			{
				ans.push_back({nums[i], nums[j], c});
				set.erase(c); // 三元组元素c去重
			}
			else
			{
				set.insert(nums[j]);
			}
		}
	}
	return ans;
}

vector<vector<int>> Solution::threeSum_2(vector<int> &nums)
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	// 找出a + b + c = 0
	// a = nums[i], b = nums[left], c = nums[right]
	for (int i = 0; i < nums.size(); i++)
	{
		// 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
		if (nums[i] > 0)
		{
			return result;
		}
		// 错误去重a方法，将会漏掉-1,-1,2 这种情况
		/*
		if (nums[i] == nums[i + 1]) {
			continue;
		}
		*/
		// 正确去重a的方法
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right)
		{
			// 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
			/*
			while (right > left && nums[right] == nums[right - 1]) right--;
			while (right > left && nums[left] == nums[left + 1]) left++;
			*/
			if (nums[i] + nums[left] + nums[right] > 0)
				right--;
			else if (nums[i] + nums[left] + nums[right] < 0)
				left++;
			else
			{
				result.push_back(vector<int>{nums[i], nums[left], nums[right]});
				// 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
				while (left < right && nums[right] == nums[right - 1])
					right--;
				while (left < right && nums[left] == nums[left + 1])
					left++;

				// 找到答案时，双指针同时收缩
				left++;
				right--;
			}
		}
	}
	return result;
}

vector<vector<int>> Solution::fourSum(vector<int> &nums, int target)
{
	vector<vector<int>> ans;
	std::sort(nums.begin(), nums.end());
	for (int k = 0; k < nums.size(); ++k)
	{
		// 剪枝处理
		if (nums[k] > target && nums[k] >= 0)
		{
			break; // 这里使用break，统一通过最后的return返回
		}
		// 对nums[k]去重
		if (k > 0 && nums[k] == nums[k - 1])
		{
			continue;
		}
		for (int i = k + 1; i < nums.size(); ++i)
		{
			// 2级剪枝处理
			if (nums[k] + nums[i] > target && nums[i] >= 0)
			{
				break;
			}
			// 对nums[i]去重
			if (i > k + 1 && nums[i] == nums[i - 1])
			{
				continue;
			}
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				// nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
				if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
					left++;
				// nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
				else if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
					right--;
				else
				{
					ans.push_back({nums[k], nums[i], nums[left], nums[right]});
					// 对nums[left]和nums[right]去重
					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;
					// 找到答案时，双指针同时收缩
					left++;
					right--;
				}
			}
		}
	}
	return ans;
}

int Solution::getIndex(int n)
{
	int totalSum = 0;
	while (n > 0)
	{
		int d = n % 10;
		n = n / 10;
		totalSum += d * d;
	}
	return totalSum;
}
