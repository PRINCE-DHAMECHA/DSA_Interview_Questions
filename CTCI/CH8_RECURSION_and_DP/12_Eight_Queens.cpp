//& Question: Write an algorithm to place 8 queens in 8*8 chess board such that no two queen share the same row,column or diagonal.

//^ Solution:

//~ Approach:
//* Here we'll use backtracking, we place queen is possible and check for next row

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* Check in columns ans diagonals
bool isSafe(vector<vector<bool>> &board, int r, int c)
{
    int maxLeft = min(r, c);
    int maxRight = min(r, int(board.size() - c - 1));
    for (int i = 0; i < r; i++)
    {
        if (board[r - i - 1][c])
        {
            return false;
        }
    }
    //* Left diagonal
    for (int i = 0; i < maxLeft; i++)
    {
        if (board[r - i - 1][c - i - 1])
        {
            return false;
        }
    }
    //* Right diagonal
    for (int i = 0; i < maxRight; i++)
    {
        if (board[r - i - 1][c + i + 1])
        {
            return false;
        }
    }
    return true;
}

bool nQueens(vector<vector<bool>> &board, int row = 0)
{
    //* After we place all queens
    if (row == board.size())
    {
        return true;
    }
    for (int col = 0; col < board.size(); col++)
    {
        if (isSafe(board, row, col))
        {
            //* Place and check if its valid or not
            board[row][col] = true;
            if (nQueens(board, row + 1))
            {
                return true;
            }
            // If its not valid then backtrack and try next combinations
            board[row][col] = false;
        }
    }
    //! If no possible way is there to place eg: 3x3 or 2x2 chess board
    return false;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<vector<bool>> board(5, vector<bool>(5, false));
    nQueens(board);
    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}