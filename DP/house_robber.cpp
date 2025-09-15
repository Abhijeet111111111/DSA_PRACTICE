#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> dp;
    int f(vector<int> nums, int i)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        if (i == nums.size() - 1)
            return nums[i];
        int c = -999;
        for (int j = i; j < nums.size(); j++)
        {
            c = max(c, nums[j] + f(nums, j + 2));
        }
        return dp[i] = c;
    }
    int rob(vector<int> &nums)
    {
        dp.resize(1000, -1);
        return f(nums, 0);
        max(dp[0], dp[1]);
    }
};