#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < digits.size(); i++)
        {
            mp[digits[i]]++;
        }
        vector<int> res;
        for (int i = 100; i <= 999; i++)
        {
            if (i % 2 == 0)
            {
                int o = i % 10;
                int t = (i / 10) % 10;
                int h = i / 100;
                if (!(mp[o] && mp[t] && mp[h]))
                    continue;
                if (o != t and o != h and h != t)
                {
                    res.push_back(i);
                    continue;
                } // all different
                if (o == t and o == h and t == h)
                {
                    if (mp[o] >= 3)
                        res.push_back(i);
                }
                else if (o == t and mp[o] > 1)
                    res.push_back(i);
                else if (o == h and mp[h] > 1)
                    res.push_back(i);
                else if (h == t and mp[t] > 1)
                    res.push_back(i);
            }
        }

        return res;
    }
};