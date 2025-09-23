#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<char, int>> pq;
        for (auto ele : mp)
            pq.push(ele);
        string ans = "";
        while (pq.size())
        {
            auto curr = pq.top();
            pq.pop();
            if (curr.second > repeatLimit)
            {
                int l = repeatLimit;
                while (l > 0)
                {
                    l--;
                    ans += curr.first;
                }
                curr.second -= repeatLimit;
                if (pq.size())
                {
                    ans += pq.top().first;
                    auto t = pq.top();
                    pq.pop();
                    t.second--;
                    if (t.second)
                        pq.push({t.first, t.second});
                    pq.push(curr);
                }
            }
            else
            {
                while (curr.second)
                {
                    ans += curr.first;
                    curr.second--;
                }
            }
        }
        return ans;
    }
};