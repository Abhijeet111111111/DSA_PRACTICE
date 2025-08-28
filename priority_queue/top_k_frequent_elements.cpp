#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto ele : mp)
        {
            min_heap.push({ele.second, ele.first});
            if (min_heap.size() > k)
                min_heap.pop();
        }
        vector<int> res;
        while (min_heap.size())
        {
            auto ele = min_heap.top();
            min_heap.pop();
            res.push_back(ele.second);
        }
        return res;
    }
};