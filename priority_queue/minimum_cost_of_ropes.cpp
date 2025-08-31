#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int e : arr)
            minH.push(e);
        int min_cost = 0;
        while (minH.size() > 1)
        {
            int curr_min = minH.top();
            minH.pop();
            int next_min = minH.top();
            minH.pop();
            min_cost += curr_min + next_min;
            minH.push(curr_min + next_min);
        }
        return min_cost;
    }
};