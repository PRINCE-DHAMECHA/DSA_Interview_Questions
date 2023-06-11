//& Question: You're given two sorted array A and B where A is large enough to store element of B. Merge B into A in Sorted order.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We start from end and add element at the end of A by comparing last element of A and B

void mergeSorted(vector<int> &A, vector<int> &B, int sizeA, int sizeB)
{
    //* Last index where we can insert element in A
    int lastInd = sizeA + sizeB - 1;
    int indA = sizeA - 1, indB = sizeB - 1;
    while (indB >= 0)
    {
        //* If element of A is bigger then push it and decrement both index
        if (A[indA] > B[indB])
        {
            A[lastInd--] = A[indA--];
        }
        else
        {
            A[lastInd--] = B[indB--];
        }
    }
    //* Note that after you ran out of elements of B you don't need to push elements of A because it'll be already in place.
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> A = {1, 2, 3, 34, 233, 3113};
    int sizeA = A.size();
    A.push_back(-1);
    A.push_back(-1);
    A.push_back(-1);
    A.push_back(-1);
    A.push_back(-1);
    vector<int> B = {3, 6, 9, 10};
    mergeSorted(A, B, sizeA, B.size());
    for (auto i : A)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}