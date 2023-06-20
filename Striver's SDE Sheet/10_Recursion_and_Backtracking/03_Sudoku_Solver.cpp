//& Solve given sudoku.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* Backtracking

bool check(vector<vector<char>> &board, int i, int j, char val)
{
    //* Checking for repetitions in row
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == val)
        {
            return false;
        }
    }
    //* Checking for repetitions in column
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == val)
        {
            return false;
        }
    }
    //* Getting start row and column for 3X3 box
    int row = i - i % 3, col = j - j % 3;
    //* Checking 3X3 box for repetitions
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[row + i][col + j] == val)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokuHelper(vector<vector<char>> &board, int r, int c)
{
    if (r == 9)
    {
        return true;
    }
    //* If we fill this column then we move on to next row
    if (c == 9)
    {
        return sudokuHelper(board, r + 1, 0);
    }
    //* If cell already filled
    if (board[r][c] != '.')
    {
        return sudokuHelper(board, r, c + 1);
    }
    for (int i = 0; i < 9; i++)
    {
        if (check(board, r, c, i + '1'))
        {
            board[r][c] = i + '1';
            if (sudokuHelper(board, r, c + 1))
            {
                return true;
            }
            board[r][c] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    sudokuHelper(board, 0, 0);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}