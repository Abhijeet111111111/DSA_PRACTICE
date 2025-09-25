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
    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        vector<vector<int>> intervals;
        for (int i = 0; i < start.size(); i++)
        {
            intervals.push_back({start[i], finish[i]});
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int c = 0;
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> currInterval = intervals[i];
            if (currInterval[0] <= lastEndTime)
            {
                c++;
            }
            else
            {
                lastEndTime = currInterval[1];
            }
        }
        return intervals.size() - c;
    }
};