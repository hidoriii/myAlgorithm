#include "Solution.h"
#include <iostream>
#include <algorithm>

bool Solution::isValid(string s)
{
    if (s.size() % 2 != 0) // 如果s的长度为奇数，一定不符合要求
        return false;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            st.push(')');
        else if (s[i] == '[')
            st.push(']');
        else if (s[i] == '{')
            st.push('}');
        // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
        // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
        else if (st.empty() || st.top() != s[i])
            return false;
        else // st.top() 与 s[i] 相等，栈弹出元素（代表匹配成功）
            st.pop();
    }
    // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
    return st.empty();
}

string Solution::removeDuplicates(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (st.empty() || st.top() != s[i])
        {
            st.push(s[i]);
        }
        else
        {
            st.pop(); // s 与 st.top()相等的情况
        }
    }
    string ans = "";
    while (!st.empty()) // 将栈中元素放到result字符串汇总
    {
        ans += st.top();
        st.pop();
    }
    std::reverse(ans.begin(), ans.end()); // 此时字符串需要反转一下
    return ans;
}

string Solution::removeDuplicates_2(string s)
{
    string ans;
    for (char ch : s)
    {
        if (ans.empty() || ans.back() != ch)
        {
            ans.push_back(ch);
        }
        else
        {
            ans.pop_back();
        }
    }
    return ans;
}

int Solution::evalRPN(vector<string> &tokens)
{
    stack<long long> st;
    for (string s : tokens)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/") // s 是运算符 就取栈顶两个元素进行运算后，再把结果入栈
        {
            long long num1 = st.top();
            st.pop();
            long long num2 = st.top();
            st.pop();
            if (s == "+")
                st.push(num2 + num1);
            if (s == "-")
                st.push(num2 - num1);
            if (s == "*")
                st.push(num2 * num1);
            if (s == "/")
                st.push(num2 / num1);
        }
        else
        {
            st.push(stoll(s)); // 如果 s 是数字，就进栈（注意要先把 string 转换成 long long 型）
        }
    }
    int ans = st.top();
    return ans;
}

vector<int> Solution::maxSlidingWindow(vector<int> &nums, int k)
{
    MyMonotonicQueue que;
    vector<int> ans;
    for (int i = 0; i < k; ++i) // 先将前k的元素放进队列
    {
        que.push(nums[i]);
    }
    ans.push_back(que.front()); // ans 记录前k的元素的最大值
    for (int i = k; i < nums.size(); ++i)
    {
        que.pop(nums[i - k]);       // 滑动窗口移除最前面元素
        que.push(nums[i]);          // 滑动窗口前加入最后面的元素
        ans.push_back(que.front()); // 记录对应的最大值
    }
    return ans;
}

vector<int> Solution::topKFrequent(vector<int> &nums, int k)
{
    // 要统计元素出现频率
    unordered_map<int, int> map; // map<num,对应出现的次数>
    for (int num : nums)
    {
        ++map[num];
    }
    // 对频率排序
    // 定义一个小顶堆，大小为 k
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   MyComparison>
        pri_que;
    // 用固定大小为 k 的小顶堆，扫面所有频率的数值
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        pri_que.push(*it);
        if (pri_que.size() > k) // 如果堆的大小大于了 k，则队列弹出，保证堆的大小一直为 k
        {
            pri_que.pop();
        }
    }
    // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
    vector<int> ans(k);
    for (int i = k - 1; i >= 0; --i)
    {
        ans[i] = pri_que.top().first;
        pri_que.pop();
    }
    return ans;
}
