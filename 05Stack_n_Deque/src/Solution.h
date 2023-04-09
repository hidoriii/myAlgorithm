#pragma
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
using std::deque;
using std::pair;
using std::priority_queue;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

class Solution
{
public:
    // 20. 有效的括号 https://leetcode.cn/problems/valid-parentheses/
    bool isValid(string s);
    // 1047. 删除字符串中的所有相邻重复项 https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
    string removeDuplicates(string s);
    string removeDuplicates_2(string s); // 直接把string当作栈，省去了将栈转换为string的操作
    // 150. 逆波兰表达式求值 https://leetcode.cn/problems/evaluate-reverse-polish-notation/
    int evalRPN(vector<string> &tokens);
    // 239. 滑动窗口最大值(Hard) https://leetcode.cn/problems/sliding-window-maximum/
    vector<int> maxSlidingWindow(vector<int> &nums, int k);
    // 347.前 K 个高频元素 https://leetcode.cn/problems/top-k-frequent-elements/
    vector<int> topKFrequent(vector<int> &nums, int k);

private:
    class MyComparison // 小顶堆的自定义比较方式
    {
        public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };

    class MyMonotonicQueue // 单调队列（从大到小）
    {
    public:
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值（即最大值），如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value)
        {
            if (!que.empty() && que.front() == value)
            {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 查询当前队列里的最大值(即出口处的元素) 直接返回队列前端也就是front就可以了。
        int front()
        {
            return que.front();
        }

    private:
        deque<int> que; // 使用deque来实现单调队列
    };
};
