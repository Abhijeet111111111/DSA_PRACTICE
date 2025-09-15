#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dp;
    int fn(int m, int n, int i, int j)
    {
        if ((i == m - 1) and (n - 1 == j))
            return 1;
        if (i > m - 1 or j > n - 1)
            return 0;
        if (dp[i][j])
            return dp[i][j];
        int a = fn(m, n, i + 1, j);
        int b = fn(m, n, i, j + 1);
        return dp[i][j] = a + b;
    }
    int uniquePaths(int m, int n)
    {
        dp.resize(100, vector<int>(100, 0));
        return fn(m, n, 0, 0);
    }
};