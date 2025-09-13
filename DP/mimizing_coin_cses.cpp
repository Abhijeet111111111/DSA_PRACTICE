#include <bits/stdc++.h>
using namespace std;

// Fast IO

vector<int> dp;

int f(vector<int> v, int sum)
{
    if (sum == 0)
        return 0;
    if (dp[sum] != -2)
        return dp[sum];
    int c = 1000001;
    for (long unsigned int j = 0; j < v.size(); j++)
    {
        if (sum - v[j] < 0)
            continue;
        c = min(c, 1 + f(v, sum - v[j]));
    }
    return dp[sum] = c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    dp.resize(sum + 1, -2);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = f(v, sum);
    if (ans == 1000001)
        cout << -1;
    else
        cout << ans;
}