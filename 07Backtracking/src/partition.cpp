#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

/**
 * @brief 131. 分割回文串
 * @see https://leetcode.cn/problems/palindrome-partitioning/submissions/
 *
 */
namespace Partition
{
    class Solution
    {
    public:
        vector<vector<string>> partition(string s)
        {
            result.clear();
            path.clear();

            // version 1: 暴力回溯法
            // backtracking(s, 0);

            // version 2: 优化回溯法
            computePalindrome(s); // 计算出所有的回文子串
            backtracking_2(s, 0);

            return result;
        }

    private:
        vector<vector<string>> result;
        vector<string> path;
        void backtracking(string s, int startIndex)
        {
            if (startIndex == s.size()) // 递归终止条件: startIndex就是切割线
            {
                result.push_back(path);
                return;
            }
            for (int i = startIndex; i < s.size(); i++)
            {
                if (isPalindrome(s, startIndex, i)) // 判断字符串s的 [startIndex, i] 是否是回文串
                {
                    path.push_back(s.substr(startIndex, i - startIndex + 1)); // 将回文串添加到路径中
                }
                else // 不是回文串，剪枝
                {
                    continue;
                }
                backtracking(s, i + 1); // 递归
                path.pop_back();        // 回溯
            }
        }
        bool isPalindrome(string s, int begin, int end) // 判断字符串s的 [begin, end] 是否是回文串
        {
            for (int i = begin, j = end; i < j; i++, j--)
                if (s[i] != s[j])
                    return false;
            return true;
        }

    private:
        // 优化版：
        vector<vector<bool>> is_palindrome; // 放事先计算好的是否回文子串的结果
        void backtracking_2(const string &s, int startIndex)
        {
            // 如果起始位置已经到达字符串的末尾，说明已经找到了一组切割方案
            if (startIndex == s.size())
            {
                result.push_back(path);
                return;
            }
            for (int i = startIndex; i < s.size(); i++)
            {
                if (is_palindrome[startIndex][i]) // 判断字符串s的 [startIndex, i] 是否是回文串
                {
                    path.push_back(s.substr(startIndex, i - startIndex + 1)); // 将回文串添加到路径中
                }
                else // 不是回文串，跳过
                {
                    continue;
                }
                backtracking_2(s, i + 1); // 递归
                path.pop_back();          // 回溯
            }
        }
        void computePalindrome(const string &s)
        {
            // is_palindrome[i][j] 表示字符串s的 [i : j] （双边包括）是否是回文子串
            is_palindrome.resize(s.size(), vector<bool>(s.size(), false)); // 根据字符串s, 刷新布尔矩阵的大小
            for (int i = s.size() - 1; i >= 0; i--)
            {
                // 需要倒序计算, 保证在i行时, i+1行已经计算好了
                for (int j = i; j < s.size(); j++)
                {
                    if (j == i)
                        is_palindrome[i][j] = true;
                    else if (j - i == 1)
                        is_palindrome[i][j] = (s[i] == s[j]);
                    else
                        is_palindrome[i][j] = (s[i] == s[j]) && is_palindrome[i + 1][j - 1];
                }
            }
        }
    };
}

int main()
{
    Partition::Solution sln;
    auto result = sln.partition("aaba");
    for (const auto &v : result)
    {
        for (const auto &s : v)
            std::cout << s << " ";
        std::cout << std::endl;
    }
    /*
    print:
        a a b a
        a aba
        aa b a
    */
    return 0;
}