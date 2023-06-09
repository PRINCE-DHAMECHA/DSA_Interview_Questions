//& Write a function to print all unique rows of the given matrix.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Pretty much self explanatory

vector<vector<int>> uniqueRow(vector<vector<int>> mat)
{
    set<vector<int>> s;
    for (auto i : mat)
    {
        s.insert(i);
    }
    vector<vector<int>> res;
    for (auto i : s)
    {
        res.push_back(i);
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<vector<int>> mat =
        {{1, 1, 1, 0, 0},
         {0, 1, 0, 0, 1},
         {1, 0, 1, 1, 0},
         {0, 1, 0, 0, 1},
         {1, 1, 1, 0, 0}};
    vector<vector<int>> res = uniqueRow(mat);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}