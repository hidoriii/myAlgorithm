#pragma
#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution
{
public:
    // 344.反转字符串 https://leetcode.cn/problems/reverse-string/
    void reverseString(vector<char> &s);
    // 541. 反转字符串II https://leetcode.cn/problems/reverse-string-ii/
    string reverseStr(string s, int k);
    // 剑指Offer 05. 替换空格 https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
    string replaceSpace(string s);
    // 151.翻转字符串里的单词 https://leetcode.cn/problems/reverse-words-in-a-string/
    string reverseWords(string s);
    // 剑指Offer 58-II. 左旋转字符串 https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
    string reverseLeftWords(string s, int n);
    // 28. 找出字符串中第一个匹配项的下标 https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
    int strStr(string haystack, string needle);   // 前缀表不减一
    int strStr_2(string haystack, string needle); // 前缀表统一减一
    // 459. 重复的子字符串 https://leetcode.cn/problems/repeated-substring-pattern/
    bool repeatedSubstringPattern(string s); // 移动匹配
    bool repeatedSubstringPattern_2(string s); // KMP
    bool repeatedSubstringPattern_3(string s); // 暴力枚举

private:
    void reverse(string &s, int start, int end);
    void removeExtraSpaces(string &s);
    void removeExtraSpaces_2(string &s);        // 双指针法
    void getNext(int *next, const string &s);   // 前缀表（不减一）
    void getNext_2(int *next, const string &s); // 前缀表（减一）
};