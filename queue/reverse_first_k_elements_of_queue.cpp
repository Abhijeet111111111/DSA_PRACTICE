#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse_first_k(int k, queue<int> &q)
{
    int s = q.size();
    k = k % s;
    int n = k;

    stack<int> st;
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }

    while (st.size())
    {
        q.push(st.top());
        st.pop();
    }

    int rem = s - n;
    for (int i = 0; i < rem; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q)
{
    while (q.size())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.push(60);
    display(qu);
    reverse_first_k(200, qu);
    display(qu);
}