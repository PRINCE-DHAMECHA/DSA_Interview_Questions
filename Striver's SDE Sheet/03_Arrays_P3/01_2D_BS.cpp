//& Given matrix which is sorted row and col wise both find given target. If present return true else false.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Treat matrix as 1D array

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int low = 0, high = (row * col) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        //* Corresponding element in matrix
        int midVal = matrix[mid / col][mid % col];
        if (midVal == target)
        {
            return true;
        }
        else if (midVal < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}