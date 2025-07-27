#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void display(queue<int> &q)
{
    int n = q.size();
    for (int i = 1; i <= n; i++)
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}
void reverseK(int k, queue<int> &q)
{
    stack<int> st;
    for (int i = 1; i <= k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (st.size() > 0)
    {
        q.push(st.top());
        st.pop();
    }
    int n = q.size();
    for (int i = 1; i <= n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    queue<int> q;
    // stack<int>st1;
    // stack<int>st2;
    // int n ;
    // cin>>n;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    display(q);

    // while (n > 0) 
    // {
    //     int x = q.front();
    //     q.pop();
    //     st2.push(x);
    //     n--;
    // }
    // while (q.size() > 0)
    // {
    //     int x = q.front();
    //     q.pop();
    //     st1.push(x);
    // }
    // while (st2.size() > 0)
    // {
    //     int x = st2.top();
    //     st2.pop();
    //     q.push(x);
    // }
    // while (st1.size() > 0)
    // {
    //     int x = st1.top();
    //     st2.push(x);
    //     st1.pop();
    // }
    // while (st2.size() > 0)
    // {
    //     int x = st2.top();
    //     q.push(x);
    //     st2.pop();
    // }

    // display(q);

    // sir's method : -

    int k = 3;
    reverseK(k, q);
    display(q);
}