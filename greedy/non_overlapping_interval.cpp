#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> i1, vector<int> i2)
{
    return i1[1] < i2[1];
}
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int lastEndTime = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> currInterval = intervals[i];
            if (currInterval[0] < lastEndTime)
            {
                ans++;
            }
            else
            {
                lastEndTime = currInterval[1];
            }
        }
        return ans;
    }
};