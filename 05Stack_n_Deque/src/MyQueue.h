#pragma
#include <stack>

// 232. 用栈实现队列 https://leetcode.cn/problems/implement-queue-using-stacks/

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stackIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stackOut.empty())
        {
            // 从stIn导入数据直到stIn为空
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result = stackOut.top();
        stackOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek()
    {
        int res = this->pop(); // 直接使用已有的pop函数
        stackOut.push(res);    // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stackIn.empty() && stackOut.empty();
    }

private:
    std::stack<int> stackIn;
    std::stack<int> stackOut;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */