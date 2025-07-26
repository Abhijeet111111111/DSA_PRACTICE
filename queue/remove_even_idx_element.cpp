#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    int i = 0;
    while (i != qu.size())
    {
        if (i % 2 == 0)
            qu.pop();
        else
        {
            int x = qu.front();
            qu.pop();
            qu.push(x);
        }
        i++;
    }
    while (qu.size())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
}