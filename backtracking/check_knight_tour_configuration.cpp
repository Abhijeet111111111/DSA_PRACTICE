#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool f(vector<vector<int>> &grid, int r, int c, int counter, vector<vector<int>> &v)
    {
        if (r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size())
            return false;

        if (grid[r][c] != -1)
            return false;

        if (counter == grid.size() * grid[0].size() - 1)
        {
            return true;
        }
        grid[r][c] = counter;
        if (grid[r][c] != v[r][c])
        {
            grid[r][c] = -1;
            return false;
        }
        // top rigt
        bool a = f(grid, r - 1, c + 2, counter + 1, v);
        if (a)
            return a;
        // top left
        bool b = f(grid, r - 1, c - 2, counter + 1, v);
        if (b)
            return b;
        // bottom rigt
        bool d = f(grid, r + 1, c + 2, counter + 1, v);
        if (d)
            return d;
        // bottom left
        bool e = f(grid, r + 1, c - 2, counter + 1, v);
        if (e)
            return e;
        // top rigt
        bool n = f(grid, r - 2, c + 1, counter + 1, v);
        // top left
        if (n)
            return n;
        bool g = f(grid, r - 2, c - 1, counter + 1, v);
        // bottom rigt
        if (g)
            return g;
        bool h = f(grid, r + 2, c + 1, counter + 1, v);
        // bottom left
        if (h)
            return h;
        bool i = f(grid, r + 2, c - 1, counter + 1, v);
        if (i)
            return i;

        grid[r][c] = -1;
        return false;
    }
};