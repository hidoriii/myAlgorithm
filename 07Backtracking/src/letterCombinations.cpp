#include <vector>
#include <string>
using std::string;
using std::vector;

namespace letterCombinations
{
    /**
     * @brief 17. 电话号码的字母组合
     * @see https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
     *
     * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
     * 给出数字到字母的映射与电话按键相同。注意 1 不对应任何字母。
     *
     * @note 回溯法
     */
    class Solution
    {
    public:
        vector<string> letterCombinations(string digits)
        {
            if (digits.size() == 0)
                return result;
            backtracking(digits, 0);
            return result;
        }

    private:
        const string letterMap[10] = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        vector<string> result;
        string path;
        void backtracking(const string &digits, int index) // index 表示处理到 digits的第几位了（即数的深度）
        {
            if (index == digits.size()) // 递归终止条件
            {
                result.push_back(path);
                return;
            }
            int digit = digits[index] - '0';   // 将 index指向的数字转换为int
            string letters = letterMap[digit]; // 取数字对应的字符集
            for (int i = 0; i < letters.size(); i++)
            {
                path.push_back(letters[i]);      // 处理
                backtracking(digits, index + 1); // 递归
                path.pop_back();                 // 回溯
            }
        }
    };
}