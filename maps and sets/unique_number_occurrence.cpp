#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        unordered_set<int> s;
        for (auto ele : mp)
        {
            if (s.find(ele.second) != s.end())
                return false;
            s.insert(ele.second);
        }
        return true;
    }
};