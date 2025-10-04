#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int>st;
void build_max_tree(vector<int> &arr,int i,int lo,int hi){
    if(lo == hi){
        st[i] = arr[lo];
        return ;
    }
    int mid = lo + (hi-lo)/2;
    build_max_tree(arr,2*i+1,lo,mid);
    build_max_tree(arr,2*i+2,mid+1,hi);
    st[i] = max(arr[2*i+1],arr[2*i+2]);
}
int getMax(int i,int lo,int hi,int &l,int &r){
    if(lo>=l and hi<=r){
        return st[i];
    }
    if(hi < l or r < lo){
        return INT_MIN;
    }
    int mid = lo + (hi-lo)/2;
    int lmax = getMax(2*i+1,lo,mid,l,r);
    int rmax = getMax(2*i+2,mid+1,hi,l,r);
    return max(lmax,rmax);

}

int main(){
    vector<int> arr = {1,4,2,8,6,4,9,3};
    st.resize(4*arr.size());
    build_max_tree(arr,0,0,arr.size()-1);
    int q;
    cin>>q;
    int l,r;
    while(q--){cin>>l>>r;cout<<getMax(0,0,arr.size()-1,l,r);}

}