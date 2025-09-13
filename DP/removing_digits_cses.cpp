#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> dp(10000001, -1);

int f(int n)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int x = n;
    int ans = INT_MAX;
    while (x)
    {
        if (x % 10)
            ans = min(ans, 1 + f(n - x % 10));
        x /= 10;
    }
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
}