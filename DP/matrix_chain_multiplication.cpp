#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int si, int ei , vector<int> v){
    if(ei < 0 || si >= v.size()) return 0;
    if(si == ei) return 0;
    int m = INT_MAX;
    for(int i=si;i<=ei;i++){
        m = min(m,f(0,i,v) + f(i,v.size()-1,v) +v[i]*v[si]*v[ei] );
    }
    return m;
}


int main(){
    vector<int>v = {40,20,30,10,30};
    cout<<f(1,v.size()-1,v);

}