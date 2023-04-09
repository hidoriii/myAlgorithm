#include "Solution.h"
#include <iostream>
#include <unordered_map>

int Solution::minSubArrayLen(int target, vector<int>& nums)
{
	int n = nums.size();
	if (n == 0)
		return 0;
	int result = INT32_MAX;
	int sum = 0; // ����������ֵ֮��
	int start = 0; // ����������ʼλ��
	int subLength = 0; // �������ڵĳ���
	for (int end = 0; end < n; end++) {
		sum += nums[end];
		// ע������ʹ��while��ÿ�θ��� i����ʼλ�ã��������ϱȽ��������Ƿ��������
		while (sum >= target) {
			subLength = end - start + 1; // ȡ�����еĳ���
			result = result < subLength ? result : subLength;
			sum -= nums[start++]; // �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
		}
	}
	// ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
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
	// ��ͳ��T�е��ַ����
	for (int i = 0; i < T.size(); ++i) {
		flag[T[i]] = true;
		++chars[T[i]];
	}
	// �ƶ��������ڣ����ϸ���ͳ������
	int cnt = 0, left = 0, min_l = 0, min_size = S.size() + 1;
	for (int right = 0; right < S.size(); ++right) {
		if (flag[S[right]]) {
			if (--chars[S[right]] >= 0)
				++cnt;
			// ��Ŀǰ���������Ѱ���t��ȫ���ַ�
			// ���Խ�left���ƣ��ڲ�Ӱ����������»��������ַ���
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
