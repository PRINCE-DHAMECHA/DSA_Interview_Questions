//&Get all subset of given set and return vector of their sum.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* We take both possibilities of taking current and not taking current to get all subset and at last we append sum.

vector<int> getSum(vector<int> &arr, int N, vector<int> &sumVector, int sumTill)
{
    if (N == 0)
    {
        sumVector.push_back(sumTill);
    }
    else
    {
        getSum(arr, N - 1, sumVector, sumTill + arr[N - 1]);
        getSum(arr, N - 1, sumVector, sumTill);
    }
    return sumVector;
}
vector<int> subsetSums(vector<int> arr, int N, int sum = 0)
{
    vector<int> sumVector;
    return getSum(arr, N, sumVector, 0);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}