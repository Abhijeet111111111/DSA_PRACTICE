#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        priority_queue<pair<int, int>> pq;
        for (auto ele : boxTypes)
        {
            int no_of_box = ele[0];
            int unit = ele[1];
            pq.push({unit, no_of_box});
        }
        int max_units = 0;
        while (pq.size())
        {
            auto ele = pq.top();
            int boxes = ele.second;
            int units = ele.first;
            pq.pop();
            if (boxes < truckSize)
            {
                max_units += units * boxes;
                truckSize -= boxes;
            }
            else
            {
                int d = truckSize;
                max_units += d * units;
                break;
            }
        }
        return max_units;
    }
};