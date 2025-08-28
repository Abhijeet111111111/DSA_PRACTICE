#include <iostream>
#include <queue>
using namespace std;
int main()
{
    vector<int> v = {10, 9, 8, 7, 4, 70, 60, 50};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    priority_queue<int, vector<int>, greater<int>> pq_min;
    int k = 4;
    int idx = 0;
    for (int i = 0; i < v.size(); i++)
    {
        pq_min.push(v[i]);
        if (pq_min.size() > k)
        {
            v[idx++] = pq_min.top();
            pq_min.pop();
        }
    }

    while (pq_min.size())
    {
        v[idx++] = pq_min.top();
        pq_min.pop();
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}