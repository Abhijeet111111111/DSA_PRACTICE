#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        vector<int> dp(1000);
        dp[0] = 0;
        dp[1] = 1;
        int i = 2;
        while (i <= n)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            i++;
        }
        return dp[n];
    }
};