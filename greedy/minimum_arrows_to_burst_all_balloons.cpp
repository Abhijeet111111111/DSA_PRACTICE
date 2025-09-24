#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        vector<vector<int>> overLap;
        overLap.push_back(points[0]);

        for (int i = 1; i < points.size(); i++)
        {
            vector<int> lastEndInterval = overLap[overLap.size() - 1];
            vector<int> currInterval = points[i];
            if (currInterval[0] <= lastEndInterval[1])
            {
                overLap[overLap.size() - 1][0] = min(currInterval[0], lastEndInterval[0]);
                overLap[overLap.size() - 1][1] = min(currInterval[1], lastEndInterval[1]);
            }
            else
            {
                overLap.push_back(currInterval);
            }
        }
        return overLap.size();
    }
};