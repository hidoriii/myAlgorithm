#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

/**
 * @brief 93. 复原IP地址
 * @see https://leetcode-cn.com/problems/restore-ip-addresses/
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 *
 * @note 回溯法
 *
 * 1. 递归函数的参数：当前处理到的字符串的下标 startIndex，已经添加了几个逗点 pointNum
 * 2. 递归函数的终止条件：pointNum == 3，表示已经添加了3个逗点，分割结束
 * 3. 递归函数的逻辑：
 *     1. 遍历字符串，从 startIndex 开始，到字符串的末尾结束
 *     2. 判断 s 的 [startIndex,i] 这个区间的子串是否合法，如果合法就继续往下递归
 *     3. 如果不合法，直接结束本层循环
 *     4. 如果合法，就在 i 的后面插入一个逗点，然后递归调用，递归调用的参数为 i+2 和 pointNum+1
 *     5. 回溯，把逗点删掉
 * 4. 判断字符串s在左闭又闭区间[left, right]所组成的数字是否合法
 *     1. 如果 s[left] == '0'，那么只有当 left == right 时，才是合法的
 *     2. 如果 s[left] != '0'，那么就要判断 s[left,right] 所组成的数字是否在 0~255 之间
 */
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        if (s.size() < 4 || s.size() > 12)
            return result;
        backtracking(s, 0, 0);
        return result;
    }

private:
    vector<string> result;
    // startIndex: 搜索的起始位置，pointNum: 添加逗点的数量
    void backtracking(string &s, int startIndex, int pointNum)
    {
        if (pointNum == 3) // 逗号数量为3时，分割结束【重点！！！】
        {
            if (isValid(s, startIndex, s.size() - 1)) // 判断第四段子字符串是否合法，如果合法就放进 result中
            {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s, startIndex, i)) // 判断 s 的 [startIndex,i] 这个区间的子串是否合法
            {
                s.insert(s.begin() + i + 1, '.'); // 在i的后面插入一个逗点
                pointNum++;                       // 逗点数量加1
                backtracking(s, i + 2, pointNum); // 插入逗点之后下一个子串的起始位置为i+2，因为要跳过逗点
                s.erase(s.begin() + i + 1);       // 回溯删掉逗点
                pointNum--;                       // 回溯
            }
            else // 不合法，直接结束本层循环
                break;
        }
    }
    // 判断字符串s在左闭又闭区间[left, right]所组成的数字是否合法
    bool isValid(const string &s, int left, int right)
    {
        if (left > right) // 左边大于右边 不合法
            return false;
        if (s[left] == '0' && left != right) // 0开头的数字 不合法
            return false;
        int num = 0;
        for (int i = left; i <= right; i++)
        {
            if (s[i] > '9' || s[i] < '0') // 遇到非数字字符 不合法
                return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255) // 如果大于255了 不合法
                return false;
        }
        return true;
    }
};