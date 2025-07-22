#include <iostream>
#include<vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> spiral;
        int l = 0;
        int r = matrix[0].size();
        int t = 0;
        int b = matrix.size();

        while (l < r)
        {

            int i = l;
            int j = t;
            while (i < r)
            {
                spiral.push_back(matrix[j][i]);
                // cout<<"a";
                i++;
            }
            t++;
            if (t >= b)
                break;
            i = r - 1;
            j = t;
            while (j < b)
            {
                spiral.push_back(matrix[j][i]);
                // cout<<"b";
                j++;
            }
            r--;
            if (l >= r)
                break;
            i = r - 1;
            j = b - 1;
            while (i >= l)
            {
                spiral.push_back(matrix[j][i]);
                // cout<<i<<" "<<j<<"\n";

                i--;
            }
            b--;
            i = b - 1;
            j = l;
            if (t >= b)
                break;
            while (i >= t)
            {
                spiral.push_back(matrix[i][j]);
                // cout<<"d";
                i--;
            }
            l++;
            if (l >= r)
                break;
        }

        return spiral;
    }
};