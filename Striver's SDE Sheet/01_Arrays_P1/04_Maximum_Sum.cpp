//& Given an integer array nums, find the subArray with the largest sum, and return its sum.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We start from beginning and calculate sum and store max of them in ans and whenever sum started going less than zero we fix it to zero because we won't consider subArray with sum less than zero
int maxSubArray(vector<int> &nums)
{
    int res = INT_MIN;
    int sum = 0;
    for (auto i : nums)
    {
        sum += i;
        res = max(res, sum);
        sum = sum < 0 ? 0 : sum;
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}