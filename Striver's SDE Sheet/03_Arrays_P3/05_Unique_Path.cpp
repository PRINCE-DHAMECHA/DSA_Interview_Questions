//& There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

//& Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We take bottom and right move in every recursion call and try to reach m and n
//* Memoization using array
//* Pretty much straight forward

int findPath(int i, int j, int m, int n, vector<vector<int>> &DP)
{
    //* If we reach at corner
    if (i == m && j == n)
    {
        return DP[i][j] = 1;
    }
    //* If we went out of the box (Don't Think Out of The Box!!)
    if (i > m || j > n)
    {
        return DP[i][j] = 0;
    }
    //* If count already calculated
    if (DP[i][j] != -1)
    {
        return DP[i][j];
    }
    //* Return possible path with both directions
    return DP[i][j] = findPath(i + 1, j, m, n, DP) + findPath(i, j + 1, m, n, DP);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> DP(102, vector<int>(102, -1));
    return findPath(1, 1, m, n, DP);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}