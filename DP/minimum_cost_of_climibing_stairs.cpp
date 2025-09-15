#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int i = 2;
        while (i < cost.size())
        {
            cost[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
            i++;
        }
        return min(cost[i - 1], cost[i - 2]);
    }
};