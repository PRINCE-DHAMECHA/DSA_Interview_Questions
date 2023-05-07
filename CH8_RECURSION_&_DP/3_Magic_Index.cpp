//& Question: A magic index in array A[0...n-1] is defined to be index such that A[i]=i. Given sorted array of distinct integers, Write a algorithm to find a magic index, If one exists.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

int BF_Magic_Index(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == i)
        {
            return i;
        }
    }
    return -1;
}

//! It'll fail if elements are not distinct
int BinSearch_Magic_Index(vector<int> &A, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (A[mid] == mid)
        {
            return mid;
        }
        //* Ex: A[5]=3, Now magic index must be at right side because it will not be possible at left side as index is already bigger than it's corresponding value, We know in best case we decrease value by one but still it'll never be equal as index should also decrease by 1.
        else if (A[mid] < mid)
        {
            return BinSearch_Magic_Index(A, mid + 1, high);
        }
        else
        {
            return BinSearch_Magic_Index(A, low, mid - 1);
        }
    }
}

//& Follow Up: Consider repetition

//* We need to search both sides as value can be repeated and our previous observation can be invalid
int Rep_BinSearch_Magic_index(vector<int> A, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int midInd = (low + high) / 2;
    int midVal = A[midInd];

    if (midInd == midVal)
    {
        return midInd;
    }

    //* Search Left
    //* If val<ind then search from 0 to val (Val is less then ind so ind need to be atleast val to val==ind) (Here we still can use sorted array property)
    //* If val>ind then search from 0 to ind-1 (Whole Left side)
    int leftIndex = min(midInd - 1, midVal);
    int checkLeft = Rep_BinSearch_Magic_index(A, 0, leftIndex);
    if (checkLeft != -1)
    {
        return checkLeft;
    }

    //* Search Right
    //* If val<ind then search from ind+1 to high
    //* If val>ind then search from val to high
    int rightIndex = max(midInd + 1, midVal);
    int checkRight = Rep_BinSearch_Magic_index(A, rightIndex, high);
    if (checkRight != -1)
    {
        return checkRight;
    }
    return -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> A = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    // cout << BF_Magic_Index(A) << endl;
    cout << BinSearch_Magic_Index(A, 0, A.size() - 1) << endl;
    vector<int> B = {-10, 1, 2, 2, 2, 3, 4, 7, 9, 12, 13};
    cout << Rep_BinSearch_Magic_index(B, 0, B.size() - 1);
    return 0;
}