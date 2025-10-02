#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int grid[4][4] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};
vector<vector<int>> dp(10, vector<int>(1024,-1));

int f(int curr, int mask, int n)
{
    if (mask == ((1 << n) - 1))
    {
        return grid[curr][0];
    }
    if (dp[curr][mask] != -1)
        return dp[curr][mask];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        bool isVisited = (mask & (1 << i)) == 0 ? 1 : 0;
        if (isVisited)
        {
            ans = min(ans, grid[curr][i] + f(i, (mask | (1 << n)), n));
        }
    }
    return dp[curr][mask] = ans;
}

int main()
{
    cout<<f(0,1,4);
}