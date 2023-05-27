#include "../include/leetcode.h"

/**
 * @brief 139. 单词拆分
 * @see https://leetcode-cn.com/problems/word-break/
 */
class Solution
{
public:
    // 动态规划 v1
    bool wordBreak(string s, vector<string> &wordDict) // 时间：O(n^3)，空间：O(n)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // 先遍历背包，再遍历物品。因为本题求的是组合数
        for (int i = 1; i <= s.size(); i++) // 遍历背包
        {
            for (int j = 0; j < i; j++) // 遍历物品
            {
                string word = s.substr(j, i - j);
                // 如果截取的 word在单词表中 且 当前 dp[j] 也在单词表中
                if (wordSet.find(word) != wordSet.end() && dp[j] == true)
                {
                    dp[i] = true;
                }
// 打印dp数组
#define PRINT_DEBUG
#ifdef PRINT_DEBUG
                for (int index = 0; index <= s.size(); index++)
                    cout << "dp[" << index << "]=" << dp[index] << " ";
                cout << endl;
#endif // PRINT_DEBUG
            }
        }
        return dp[s.size()];
    }

    // 动态规划 v2
    bool wordBreak_2(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, 0); // dp[i]表示以i结尾的子串是否可以被拆分
        dp[0] = true;                     // 空串可以被拆分（一定要初始化为true，否则后面的递归公式推不出来）
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end())
                {
                    dp[i] = true;
                    break;
                }
// 打印dp数组
#define PRINT_DEBUG_V2
#ifdef PRINT_DEBUG_V2
                for (int index = s.size(); index >= 0; --index)
                    cout << "dp[" << index << "]=" << dp[index] << " ";
                cout << endl;
#endif // PRINT_DEBUG_V2
            }
        }
        cout << "dp[" << s.size() << "]=" << dp[s.size()] << endl;
        return dp[s.size()];
    }

    // 回溯法
    bool wordBreak_3(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), 1); // 1 表示初始化状态
        return backtracking(s, wordSet, memory, 0);
    }

private:
    bool backtracking(const string &s, const unordered_set<string> &wordSet, vector<bool> &memory, int startIndex)
    {
        if (startIndex == s.size())
        {
            return true;
        }
        if (!memory[startIndex]) // 如果memory[startIndex]不是初始值了，直接使用memory[startIndex]的结果
            return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++)
        {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, memory, i + 1))
            {
                return true;
            }
        }
        memory[startIndex] = false; // 记录以 startIndex开始的子串是不可以被拆分的
        return false;
    }
};

int main()
{
    Solution sln;
    string s("applepenapple");
    vector<string> wordDict = {"apple", "pen"};
    bool ans = sln.wordBreak(s, wordDict);
    cout << ans << endl;

    return 0;
}