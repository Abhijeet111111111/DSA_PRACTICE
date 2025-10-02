#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    void f(vector<string> &v, int n, int r, int leftMask, int rightMask, int mask)
    {
        if (r == n)
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            bool canNotPlace = (rightMask & (1 << (r + i))) or (leftMask & (1 << (r - i + n - 1))) or (mask & (1 << i));
            if (canNotPlace)
                continue;
            v[r][i] = 'Q';
            f(v, n, r + 1, (leftMask | (1 << (r - i + n - 1))), (rightMask | (1 << (r + i))), (mask | (1 << i)));
            v[r][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string s;
        s.resize(n, '.');
        vector<string> v(n, s);
        f(v, n, 0, 0, 0, 0);
        return ans;
    }
};