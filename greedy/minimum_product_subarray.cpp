#include <iostream>
#include <vector>
using namespace std;

int minProduct(vector<int> arr)
{
    int positive_product = 1;
    int negative_product = 1;
    bool isZero = false;
    int max_neg = -999999;
    int min_pos = 9999999;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            positive_product *= arr[i];
            min_pos = min(min_pos, arr[i]);
        }
        else if (arr[i] < 0)
        {
            negative_product *= arr[i];
            max_neg = max(max_neg, arr[i]);
        }
        else
        {
            isZero = true;
        }
    }
    if (negative_product < 0)
    {
        return negative_product * positive_product;
    }
    else if(negative_product > 1){
        return negative_product * positive_product / max_neg;
    }
    else if (isZero)
        return 0;
    else
        return min_pos;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<minProduct(v);
}