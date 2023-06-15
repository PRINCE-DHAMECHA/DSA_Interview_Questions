//& Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

//! You must do it in place.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* Here we use first row and first column as boolean which indicates that which row and col we need to make zero
//* Ex:- if we encounter matrix[2,3] as 0 then we make matrix[0,3] and matrix[2,0] zero and after this nested loop we check first ro and col and if it's zero then we make corresponding row or col zero.
//* To use first row and col first we need to check whether that row or col will be zero or not

void setZeroes(vector<vector<int>> &matrix)
{
    bool isRowZero = false, isColZero = false;
    //* Check whether first col contains zero or not because in nested loop we set some of its value to zero and after that if it contains zero before or not we can't remember
    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == 0)
        {
            isRowZero = true;
        }
    }
    //* Same as col for row
    for (int j = 0; j < matrix.size(); j++)
    {
        if (matrix[j][0] == 0)
        {
            isColZero = true;
        }
    }
    //* check all matrix for zero
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                //* make corresponding row and col element in first row and col zero
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    //* check first col and wherever it contains zero set that row zero
    //! Start with 1 because if you start with 0 then if matrix[0][0] is zero then it will make corresponding all row zero and in next below loop all matrix will be zero
    for (int i = 1; i < matrix.size(); i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    //* same as col
    for (int i = 1; i < matrix[0].size(); i++)
    {
        if (matrix[0][i] == 0)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    //* set all first row zero if and only if it contains zero before
    if (isRowZero)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[0][j] = 0;
        }
    }
    //* same as row
    if (isColZero)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[j][0] = 0;
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}