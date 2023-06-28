//& You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use BFS to traverse all rotten mangoes and add oranges which affected by rotten and also store it's time when it affected for next minutes.

int orangesRotting(vector<vector<int>> &grid)
{
    int count = 0;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                q.push(make_tuple(i, j, 0));
            }
            if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    int minutes = 0;
    while (q.size() && count)
    {
        auto t = q.front();
        q.pop();
        int x = get<0>(t);
        int y = get<1>(t);
        int maxi = get<2>(t);
        if (x != 0)
        {
            if (grid[x - 1][y] == 1)
            {
                grid[x - 1][y] = 2;
                q.push(make_tuple(x - 1, y, maxi + 1));
                minutes = max(minutes, maxi + 1);
                count--;
            }
        }
        if (x != grid.size() - 1)
        {
            if (grid[x + 1][y] == 1)
            {
                grid[x + 1][y] = 2;
                q.push(make_tuple(x + 1, y, maxi + 1));
                minutes = max(minutes, maxi + 1);
                count--;
            }
        }
        if (y != grid[0].size() - 1)
        {
            if (grid[x][y + 1] == 1)
            {
                grid[x][y + 1] = 2;
                q.push(make_tuple(x, y + 1, maxi + 1));
                minutes = max(minutes, maxi + 1);
                count--;
            }
        }
        if (y != 0)
        {
            if (grid[x][y - 1] == 1)
            {
                grid[x][y - 1] = 2;
                q.push(make_tuple(x, y - 1, maxi + 1));
                minutes = max(minutes, maxi + 1);
                count--;
            }
        }
    }
    return count == 0 ? minutes : -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}