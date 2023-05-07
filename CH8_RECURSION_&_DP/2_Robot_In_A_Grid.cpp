//& Question: Imagine a robot sitting on upper left corner of grid with r rows and c columns. The robot can only move in two directions, right and down, but certain cells re "off limit" such that the robot can't step on them. Design an algorithm to find path for the robot from the top-left to the bottom-right.
//? We need to find only one path

//^ Solution:
//~ We start in reverse manner, We assume that our robot is at bottom-right and we need to find adjacent block such that our robot can reach (r-1,c) or (r,c-1), and we do recursive approach to reach this (r-1,c) or (r,c-1) unless we reach to (0,0)

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

vector<vector<int>> isReachable(100, vector<int>(100, -1));

//! Don't use x and y as grid[x][y], because it'll be confusing if you thing xx as horizontal, But actually it's a row manner and same goes for y, so use r(row) and c(column) or just use i and j
bool print_path(vector<vector<int>> &grid, int r, int c, string s)
{
    //* If we already know that path to r and c exist then we won't caluclate it again
    if (r >= 0 && c >= 0 && isReachable[r][c] != -1)
    {
        return isReachable[r][c] == 1 ? true : false;
    }
    //* We assume that in starting there's no path to r and c
    bool success = false;

    //* Conditions for invalid path, Return immediately otherwise it will be in infinite loop
    if (r < 0 || c < 0 || grid[r][c] != 0)
    {
        return false;
    }

    //* If we reach at origin we know that we followed valid path and we make success true
    if (r == 0 && c == 0)
    {
        cout << s << endl;
        success = true;
        // return true;
    }
    //* If it's not origin then we check for both possibilities
    //* is r-1 will be true then we don't consider c-1 even if there's valid path
    //* With writing r-1 first, We are making up move a priority, So if up move will make valid path we'll not consider left move.
    if (!success && (print_path(grid, r - 1, c, "D" + s) || print_path(grid, r, c - 1, "R" + s)))
    {
        success = true;
    }
    isReachable[r][c] = success ? 1 : 0;
    return success;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<vector<int>> grid = {
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
    };
    print_path(grid, grid.size() - 1, grid[0].size() - 1, "");

    return 0;
}