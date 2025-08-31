#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxH;
        for (int i = 0; i < stones.size(); i++)
        {
            maxH.push(stones[i]);
        }
        while (maxH.size() > 1)
        {
            int curr_max = maxH.top();
            maxH.pop();
            int next_max = maxH.top();
            maxH.pop();
            if (curr_max != next_max)
            {
                maxH.push(abs(curr_max - next_max));
            }
        }
        if (!maxH.size())
            return 0;
        return maxH.top();
    }
};