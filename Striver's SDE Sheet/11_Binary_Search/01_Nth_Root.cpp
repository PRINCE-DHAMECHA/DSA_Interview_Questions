//* Find nth root of given number.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Binary search

int NthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        double ans = pow(mid, n);
        if (ans < m)
        {
            low = mid + 1;
        }
        else if (ans > m)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}