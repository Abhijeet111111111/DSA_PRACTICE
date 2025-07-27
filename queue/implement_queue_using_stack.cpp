#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        while (st1.size())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int top_ele = st2.top();
        st2.pop();
        while (st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return top_ele;
    }

    int peek()
    {
        while (st1.size())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int top_ele = st2.top();
        while (st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return top_ele;
    }

    bool empty()
    {
        if (!st1.size())
            return true;
        return false;
    }
};