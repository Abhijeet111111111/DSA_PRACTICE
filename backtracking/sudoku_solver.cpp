#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<vector<char>> &board, int r, int c, int n)
    {
        int i = 0;
        int j = 8;
        while (j >= 0)
        {
            if (board[r][j] == (n + '0'))
                return false;
            j--;
        }
        while (i < board.size())
        {
            if (board[i][c] == (n + '0'))
                return false;
            i++;
        }
        int sr = (r / 3) * 3;
        int sc = (c / 3) * 3;
        for (int i = sr; i < sr + 3; i++)
        {
            for (int j = sc; j < sc + 3; j++)
            {
                if (board[i][j] == (n + '0'))
                    return false;
            }
        }
        return true;
    }

    bool f(vector<vector<char>> &board, int r, int c)
    {
        if (r == board.size())
            return true;
        if (r == board.size() and c == board.size())
            return true;

        if (c == board[0].size())
        {
            return f(board, r + 1, 0);
        }
        for (int j = 1; j <= 9; j++)
        {

            if (board[r][c] != '.')
            {
                return f(board, r, c + 1);
            }
            else if (isPossible(board, r, c, j))
            {
                board[r][c] = '0' + j;
                bool res = f(board, r, c + 1);
                if (!res)
                {
                    board[r][c] = '.';
                }
                else
                    return true;
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        f(board, 0, 0);
    }
};