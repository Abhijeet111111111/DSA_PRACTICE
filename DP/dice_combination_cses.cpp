#include<iostream>
#include<vector>
using namespace std;

vector<long>dp;

long f(long sum){

    if(sum == 0) return 1;
    if(dp[sum]!=-1) return dp[sum];
    long count = 0;
    for(long i=1;i<=6;i++){
        if(sum-i < 0) continue;
        count += f(sum-i);
        count %= 1000000007;
    }

    return dp[sum] = count;

}

int main(){
    long n;
    cin>>n;
    dp.resize(n+1,-1);
    cout<<f(n);

}