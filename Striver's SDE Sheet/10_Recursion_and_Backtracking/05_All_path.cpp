//& Suppose there's MxN matrix and rat is at (0,0) find all possible paths for (m-1,n-1).
//& Note that rat can move in any direction.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Backtrack

void allPath(int i, int j, vector<vector<int>> &maze, vector<string> &ans, string ori = "")
{
    //* If we reach destination
    if (i == maze.size() - 1 && j == maze[0].size() - 1 && maze[i][j] != 0)
    {
        ans.push_back(ori);
        return;
    }
    //* If obstacle encountered then return
    if (!maze[i][j])
    {
        return;
    }
    //* Make current false to avoid cycle
    maze[i][j] = false;
    //* Explore all directions
    if (i < maze.size() - 1)
    {
        allPath(i + 1, j, maze, ans, ori + 'D');
    }
    if (j < maze[0].size() - 1)
    {
        allPath(i, j + 1, maze, ans, ori + 'R');
    }
    if (j > 0)
    {
        allPath(i, j - 1, maze, ans, ori + 'L');
    }
    if (i > 0)
    {
        allPath(i - 1, j, maze, ans, ori + 'U');
    }
    //* Make current true for next possibility
    maze[i][j] = true;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    allPath(0, 0, m, ans, "");
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}