#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// errorrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr

int main()
{
    int k;
    cin >> k;

    vector<int> v = {0, -1, -2, 3, 4, -5, 6, 4, 7, -8};
    queue<int> neg_ele_idx;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < 0)
            neg_ele_idx.push(i);
    }
    vector<int> ans;

    int n = v.size();
    int i = 0;
    while (i < n - k)
    {
        if ((i + k > neg_ele_idx.front()) && (neg_ele_idx.front() >= i))
            ans.push_back(v[neg_ele_idx.front()]);
        else
        {
            neg_ele_idx.pop();
            continue;
        }

        i++;
    }

    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
