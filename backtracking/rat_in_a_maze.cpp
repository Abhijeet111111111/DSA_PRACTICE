#include <iostream>
#include <vector>
using namespace std;

int f(vector<vector<int>> &maze, int r, int c)
{
    if (r < 0 or c < 0 or r >= maze.size() or c >= maze.size())
    {
        return 0;
    }
    if (maze[r][c] == 1)
        return 0;
    if (r == maze.size() - 1 and c == maze.size() - 1)
        return 1;
    maze[r][c] = 1;
    // right
    int a = f(maze, r, c + 1);
    // left
    int b = f(maze, r, c - 1);
    // up
    int e = f(maze, r - 1, c);
    // down
    int d = f(maze, r + 1, c);

    maze[r][c] = 0;

    return (a + b + e + d);
}

int main()
{
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 0, 0},
    };

    cout<<f(maze,0,0);
}