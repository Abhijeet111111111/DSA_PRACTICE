#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[-nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        for (auto ele : mp)
        {
            minH.push({ele.second, ele.first});
        }
        vector<int> res;
        while (minH.size())
        {
            auto ele = minH.top();
            while (ele.first)
            {
                ele.first--;
                res.push_back(-ele.second);
            }
            minH.pop();
        }
        return res;
    }
};