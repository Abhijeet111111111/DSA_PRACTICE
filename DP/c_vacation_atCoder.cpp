#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> dp;
vector<int> dpp(1000, -1);
int f(vector<vector<int>> v, int i, char d)
{
    if (i >= n)
        return 0;
    int sum = 0;
    if (d != 'a')
    {
        if (dp[i][0] != -1)
        {
            sum = max(sum, dp[i][0]);
        }
        else
        {
            int a = f(v, i + 1, 'a');
            sum = max(sum, a + v[i][0]);
            dp[i][0] = a + v[i][0];
        }
    }
    if (d != 'b')
    {
        if (dp[i][1] != -1)
        {
            sum = max(sum, dp[i][1]);
        }
        else
        {
            int b = f(v, i + 1, 'b');
            sum = max(sum, b + v[i][1]);
            dp[i][1] = b + v[i][1];
        }
    }
    if (d != 'c')
    {
        if (dp[i][2] != -1)
        {
            sum = max(sum, dp[i][2]);
        }
        else
        {
            int c = f(v, i + 1, 'c');
            sum = max(sum, c + v[i][2]);
            dp[i][2] = c + v[i][2];
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false); // Disable synchronization with C streams
    cin.tie(nullptr);
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    dp.resize(n + 1, vector<int>(3, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << f(v, 0, 'x');
}