//& Given an m x n 2D grid map of '1’s which represents land and '0’s that represents water return the number of islands (surrounded by water and formed by connecting adjacent lands in 2 directions - vertically or horizontally).

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void BFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
    {
        return;
    }
    if (grid[i][j] == '1' && !visited[i][j])
    {
        visited[i][j] = true;
        BFS(grid, visited, i + 1, j);
        BFS(grid, visited, i, j + 1);
        BFS(grid, visited, i - 1, j);
        BFS(grid, visited, i, j - 1);
        return;
    }
}
int numIslands(vector<vector<char>> &grid)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                count++;
                BFS(grid, visited, i, j);
            }
        }
    }
    return count;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<vector<char>> grid = {{'1', '1', '1', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '1'},
                                 {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}
