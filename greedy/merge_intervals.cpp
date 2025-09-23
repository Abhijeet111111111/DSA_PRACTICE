#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < v.size(); i++)
        {
            pq.push({v[i][0], v[i][1]});
        }
        vector<vector<int>> ans;
        while (pq.size())
        {
            auto curr = pq.top();
            pq.pop();
            if (pq.top().first <= curr.second && pq.size())
            {
                auto el = pq.top();
                pq.pop();
                int s = max(el.second, curr.second);
                pq.push({curr.first, s});
            }
            else
            {
                vector<int> t = {curr.first, curr.second};
                ans.push_back(t);
            }
        }
        return ans;
    }
};