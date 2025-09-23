#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int m = 6, n = 4;
    vector<int>x = {2,1,3,1,4};
    vector<int>y = {4,1,2};
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    int h = 1;
    int v = 1;
    int total = 0;

    int i = m-2;
    int j = n-2;

    while(i >= 0 && j >= 0){
        if(x[i] >= y[j]){
            total += (h*x[i]);
            v ++;
            i--;
        }
        else {
            total += (v*y[j]);
            h ++;
            j --;
        }
    }
    if(i >= 0){
        total += (h*x[i]);
            v ++;
            i--;
    }
    else if(j >= 0){
        total += (v*y[j]);
            h ++;
            j --;
    }
    cout<<total;

}