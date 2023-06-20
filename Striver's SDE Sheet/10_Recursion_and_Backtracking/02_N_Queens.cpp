//& Find all possible positions to place N queens.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use backtracking

//* Function to check if we can place queen at (r,c) or not.
bool isSafe(vector<string> &board, int r, int c)
{
    int maxLeft = min(r, c);
    int maxRight = min(r, int(board.size() - c - 1));
    for (int i = 0; i < r; i++)
    {
        if (board[r - i - 1][c] == 'Q')
        {
            return false;
        }
    }
    for (int i = 0; i < maxLeft; i++)
    {
        if (board[r - i - 1][c - i - 1] == 'Q')
        {
            return false;
        }
    }
    for (int i = 0; i < maxRight; i++)
    {
        if (board[r - i - 1][c + i + 1] == 'Q')
        {
            return false;
        }
    }
    return true;
}
void nQueens(vector<string> &board, vector<vector<string>> &ans, int row = 0)
{
    if (row == board.size())
    {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < board.size(); col++)
    {
        //* If we can place then we place and recurse to next level and after that we remove from current location and check for next
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            nQueens(board, ans, row + 1);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string col;
    for (int i = 0; i < n; i++)
    {
        col += '.';
    }
    for (int i = 0; i < n; i++)
    {
        board[i] = col;
    }
    nQueens(board, ans, 0);
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}