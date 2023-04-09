#include "Solution.h"
#include <algorithm>

void Solution::reverseString(vector<char> &s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        std::swap(s[i], s[j]);
    }
}

string Solution::reverseStr(string s, int k)
{
    for (int i = 0; i < s.size(); i += (2 * k))
    {
        // 1. 每隔 2k 个字符的前 k 个字符进行反转
        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
        if (i + k <= s.size())
        {
            std::reverse(s.begin() + i, s.begin() + i + k);
        }
        else
        {
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            std::reverse(s.begin() + i, s.end());
        }
    }
    return s;
}

string Solution::replaceSpace(string s)
{
    int numberOfBlank = 0; // 统计空格的个数
    int originalSize = s.size();
    for (int i = 0; i < originalSize; ++i)
    {
        if (s[i] == ' ')
        {
            ++numberOfBlank;
        }
    }
    int newSize = originalSize + numberOfBlank * 2;
    s.resize(newSize);
    for (int i = newSize - 1, j = originalSize - 1; j < i; i--, j--)
    {
        if (s[j] == ' ')
        {
            s[i] = '0';
            s[i - 1] = '2';
            s[i - 2] = '%';
            i -= 2;
        }
        else
        {
            s[i] = s[j];
        }
    }
    return s;
}

string Solution::reverseWords(string s)
{
    removeExtraSpaces_2(s); // 去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格
    reverse(s, 0, s.size() - 1);
    int start = 0; // removeExtraSpaces后保证第一个单词的开始下标一定是0
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ' || i == s.size()) // 到达空格或者串尾，说明一个单词结束。进行翻转
        {
            reverse(s, start, i - 1); // 翻转，注意是左闭右闭 []的翻转
            start = i + 1;            // 更新下一个单词的开始下标start
        }
    }
    return s;
}

string Solution::reverseLeftWords(string s, int n)
{
    reverse(s, 0, n - 1);
    reverse(s, n, s.size() - 1);
    reverse(s, 0, s.size() - 1);
    return s;
}

int Solution::strStr(string haystack, string needle)
{
    if (needle.size() == 0)
    {
        return 0;
    }
    int next[needle.size()];
    getNext(next, needle);
    int j = 0;                                // 因为next数组里记录的起始位置为0
    for (int i = 0; i < haystack.size(); i++) // 注意i就从0开始
    {
        while (j > 0 && haystack[i] != needle[j]) // 不匹配
        {
            j = next[j - 1]; // j 寻找之前匹配的位置
        }
        if (haystack[i] == needle[j]) // 匹配，j和i同时向后移动
        {
            j++; // i的增加在for循环里
        }
        if (j == needle.size()) // 文本串s里出现了模式串needle
        {
            return (i - needle.size() + 1);
        }
    }
    return -1;
}

int Solution::strStr_2(string haystack, string needle)
{
    if (needle.size() == 0)
    {
        return 0;
    }
    int next[needle.size()];
    getNext_2(next, needle);
    int j = -1;                               // 因为next数组里记录的起始位置为-1
    for (int i = 0; i < haystack.size(); i++) // 注意i就从0开始
    {
        while (j >= 0 && haystack[i] != needle[j + 1]) // 不匹配
        {
            j = next[j]; // j 寻找之前匹配的位置
        }
        if (haystack[i] == needle[j + 1]) // 匹配，j和i同时向后移动
        {
            j++; // i的增加在for循环里
        }
        if (j == (needle.size() - 1)) // 文本串s里出现了模式串needle
        {
            return (i - needle.size() + 1);
        }
    }
    return -1;
}

bool Solution::repeatedSubstringPattern(string s) // O(m + n)
{
    string t = s + s;
    t.erase(t.begin());   // 掐头
    t.erase(t.end() - 1); // 去尾
    if (t.find(s) != std::string::npos)
        return true;
    return false;
}

bool Solution::repeatedSubstringPattern_2(string s)
{
    if (s.size() == 0)
    {
        return false;
    }
    int next[s.size()];
    getNext(next, s);
    int len = s.size();
    if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
    {
        return true;
    }
    return false;
}

bool Solution::repeatedSubstringPattern_3(string s) // O(m * n)
{
    int n = s.size();
    for (int i = 0; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            bool match = true;
            for (int j = i; j < n; ++j)
            {
                if (s[j] != s[j - i])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return true;
            }
        }
    }
    return false;
}

// private:

/**
 * @brief 翻转字符串s，注意是左闭右闭 [start,end]
 *
 * @param s
 * @param start 起始索引
 * @param end 末尾索引
 */
void Solution::reverse(string &s, int start, int end)
{ // 反转字符串s中左闭右闭的区间[start, end]
    for (int i = start, j = end; i < j; i++, j--)
    {
        std::swap(s[i], s[j]);
    }
}

/**
 * @brief 移除字符串s中冗余的空格（双指针法）
 *
 * @param s
 */
void Solution::removeExtraSpaces(string &s)
{
    int slow = 0, fast = 0; // 定义快指针，慢指针
    // 去掉字符串前面的空格(前导空格)
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ')
    {
        fast++;
    }
    for (; slow < fast; fast++)
    {
        // 去掉字符串中间部分的冗余空格
        if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
        {
            continue;
        }
        else
        {
            s[slow++] = s[fast];
        }
    }
    // 去掉字符串末尾的空格
    if (slow - 1 > 0 && s[slow - 1] == ' ')
    {
        s.resize(slow - 1);
    }
    else
    {
        s.resize(slow);
    }
}

/**
 * @brief 去除所有空格并在相邻单词之间添加空格, 快慢指针（参考 https://programmercarl.com/0027.移除元素.html）
 *
 * @param s
 */
void Solution::removeExtraSpaces_2(string &s)
{
    int slow = 0; // 整体思想参考 https://programmercarl.com/0027.移除元素.html
    for (int fast = 0; fast < s.size(); ++fast)
    {
        if (s[fast] != ' ')
        {                  // 遇到非空格就处理，即删除所有空格
            if (slow != 0) // 手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格
                s[slow++] = ' ';
            while (fast < s.size() && s[fast] != ' ')
            { // 补上该单词，遇到空格说明单词结束
                s[slow++] = s[fast++];
            }
        }
    }
    s.resize(slow); // slow的大小即为去除多余空格后的大小
}

/**
 * @brief 获取next数组（不进行减一操作）
 *
 * @param next next数组
 * @param s 模式串
 */
void Solution::getNext(int *next, const string &s)
{
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); i++) // 注意i从1开始
    {
        while (j > 0 && s[i] != s[j]) // j要保证大于0，因为下面有取j-1作为数组下标的操作
        {
            j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
        }
        if (s[i] == s[j]) // 找到相同的前后缀
        {
            j++;
        }
        next[i] = j; // 将j（前缀的长度）赋给next[i]
    }
}

void Solution::getNext_2(int *next, const string &s)
{
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); i++) // 注意i从1开始
    {
        while (j >= 0 && s[i] != s[j + 1])
        {                // 前后缀不相同了
            j = next[j]; // 向前回退
        }
        if (s[i] == s[j + 1])
        { // 找到相同的前后缀
            j++;
        }
        next[i] = j; // 将j（前缀的长度）赋给next[i]
    }
}