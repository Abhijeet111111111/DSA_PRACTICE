#include <iostream>
#include <vector>

using namespace std;

vector<int>dp(1000001,-1);

int f(int n)
{
    if (n == 1 or n == 0)
        return 0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] =  min(1 + f(n - 1), min(n % 2 == 0 ? (1 + f(n / 2)) : 1000, n % 3 == 0 ? (1 + f(n / 3)) : 1000));
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
}