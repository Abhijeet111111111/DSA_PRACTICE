#include <queue>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> pq;
        for (int i = 0; i < points.size(); i++)
        {
            int abs_sum = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push({abs_sum, points[i]});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> res;
        while (pq.size())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};