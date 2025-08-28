#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i < arr.size(); i++)
        {
            int dist = abs(arr[i] - x);
            max_heap.push({dist, arr[i]});
            if (max_heap.size() > k)
                max_heap.pop();
        }
        vector<int> res;
        while (max_heap.size())
        {
            auto ele = max_heap.top();
            res.push_back(ele.second);
            max_heap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};