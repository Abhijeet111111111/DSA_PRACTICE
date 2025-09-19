#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        while (k)
        {
            int curr = pq.top();
            pq.pop();
            pq.push(-curr);
            k--;
        }
        int sum = 0;
        while (pq.size())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};