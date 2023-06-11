//& Question: Given MxN matrix in which each row and column is sorted, find given key.

//^ Solution

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* At first we can use binary search in each row which take O(M logN) time.

//~ Approach:2 :-
//* We can start with any corner and reduce our search area.

vector<int> search(vector<vector<int>> mat, int key)
{
    int row = 0, col = mat[0].size() - 1;
    while (row < mat.size() && col >= 0)
    {
        if (mat[row][col] == key)
        {
            return {row, col};
        }
        //* We are starting from beginning of column so we know that if we encounter larger value then our key will not be in this column and we decrease the column
        else if (mat[row][col] > key)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return {0};
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<vector<int>> mat = {{15, 20, 40, 85}, {20, 35, 80, 95}, {30, 55, 95, 105}, {40, 80, 100, 120}};
    cout << search(mat, 30)[0] << endl;
    return 0;
}