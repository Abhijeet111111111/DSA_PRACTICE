#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    Solution()
    {
        dp.resize(31, vector<int>(1001, -1));
    }
    int numRollsToTarget(int n, int k, int target)
    {
        if (target == 0 and n == 0)
            return 1;
        else if (target < 0)
            return 0;
        else if (n == 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int count = 0;
        for (int j = 1; j <= k; j++)
        {
            count += numRollsToTarget(n - 1, k, target - j);
            count %= 1000000007;
        }

        return dp[n][target] = count;
    }
};