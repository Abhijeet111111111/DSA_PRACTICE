#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v = {{0, 11, 16, 5, 20}, {17, 4, 19, 10, 15}, {12, 1, 8, 21, 6}, {3, 18, 23, 14, 9}, {24, 13, 2, 7, 22}};

void f(vector<vector<int>> &grid, int r, int c, int counter)
{
    if (r < 0 or c < 0 or r >= grid.size() or c >= grid[0].size())
        return;

    if (grid[r][c] != -1)
        return;

    if (counter == grid.size() * grid[0].size() - 1)
    {
        grid[r][c] = counter;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        grid[r][c] = -1;
        cout << "*************************\n";
        return;
    }
    // cout<<"r";
    grid[r][c] = counter;
    // top rigt
    f(grid, r - 1, c + 2, counter + 1);
    // top left
    f(grid, r - 1, c - 2, counter + 1);
    // bottom rigt
    f(grid, r + 1, c + 2, counter + 1);
    // bottom left
    f(grid, r + 1, c - 2, counter + 1);
    // top rigt
    f(grid, r - 2, c + 1, counter + 1);
    // top left
    f(grid, r - 2, c - 1, counter + 1);
    // bottom rigt
    f(grid, r + 2, c + 1, counter + 1);
    // bottom left
    f(grid, r + 2, c - 1, counter + 1);

    grid[r][c] = -1;
}

int main()
{
    vector<vector<int>> grid(5, vector<int>(5, -1));
    f(grid, 0, 0, 0);
}