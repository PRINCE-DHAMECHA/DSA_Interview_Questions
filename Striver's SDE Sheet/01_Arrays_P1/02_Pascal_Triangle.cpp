//& Given an integer numRows, return the first numRows of Pascal's triangle.

//& Ex: 5->
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Pretty much straight forward
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    res.push_back({1});
    if (numRows == 1)
    {
        return res;
    }
    res.push_back({1, 1});
    if (numRows == 2)
    {
        return res;
    }
    for (int i = 0; i < numRows - 2; i++)
    {
        vector<int> temp(res[res.size() - 1].size() + 1, 1);
        for (int j = 1; j < temp.size() - 1; j++)
        {
            temp[j] = res[res.size() - 1][j - 1] + res[res.size() - 1][j];
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}