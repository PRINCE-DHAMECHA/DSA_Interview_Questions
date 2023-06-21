//& Find Kth element in given two sorted arrays.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use same approach as we use for in finding median

int kthElement(int arr1[], int arr2[], int m, int n, int k)
{
    if (m > n)
    {
        return kthElement(arr2, arr1, n, m, k);
    }
    //* We need to take care of k
    //* low and high will be like this to avoid edge cases
    //* If k is bigger than n then we can't start low from 0 as there won't be sufficient elements and same for high
    int low = max(0, k - n), high = min(k, m);
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == m ? INT_MAX : arr1[cut1];
        int r2 = cut2 == n ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}