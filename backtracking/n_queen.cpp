#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    bool canPlace(vector<string> v, int n, int col, int row)
    {
        // col attack
        for (int i = 0; i < n; i++)
        {
            if (v[i][col] == 'Q')
                return false;
        }
        // dia left attack
        int r = row;
        int c = col;
        while (r >= 0 and c >= 0)
        {
            if (v[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        // dia right attack
        r = row;
        c = col;
        while (r >= 0 and c < n)
        {
            if (v[r][c] == 'Q')
                return false;
            r--;
            c++;
        }
        return true;
    }

    void f(vector<string> &v, int n, int r)
    {

        if (r == n)
        {
            ans.push_back(v);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (!canPlace(v, n, i, r))
                continue;
            v[r][i] = 'Q';
            f(v, n, r + 1);
            v[r][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string s;
        s.resize(n, '.');
        vector<string> v(n, s);
        f(v, n, 0);
        return ans;
    }
};