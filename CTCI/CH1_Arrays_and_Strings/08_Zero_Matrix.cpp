//& Question:  If you encounter any cell in matrix zero then set it's row and column to zero.

//^ Solution:
//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* Seems easy? just iterate and when you find zero assign it's row and column zero. right?
//* If you make row and column zero then you can't iterate through this row and column because if you continue then whole matrix becomes zero because we can't remember every value before making it zero.
//* So use same dim matrix with booleans and set true in this matrix in corresponding place and do second pass

void setZero(vector<vector<int>> &mat)
{
    vector<vector<bool>> flags(mat.size(), vector<bool>(mat[0].size(), false));
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                flags[i][j] = true;
            }
        }
    }
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (flags[i][j])
            {
                for (int p = 0; p < mat[0].size(); p++)
                {
                    mat[i][p] = 0;
                }
                for (int q = 0; q < mat.size(); q++)
                {
                    mat[q][j] = 0;
                }
            }
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<vector<int>> v = {{1, 2, 0, 4}, {5, 6, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 16}};
    setZero(v);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
