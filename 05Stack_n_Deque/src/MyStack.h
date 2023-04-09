#pragma
#include <queue>

// 225. 用队列实现栈 https://leetcode.cn/problems/implement-stack-using-queues/

class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int size = que.size();
        while(size-- != 1)
        {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }

    int top()
    {
        return que.back();
    }

    bool empty()
    {
        return que.empty();
    }

private:
    std::queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */