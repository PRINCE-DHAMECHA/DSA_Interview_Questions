//& Given train arrival time and departure time find minimum platform needed to accommodate trains.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We sort both arrival and departure time and then start counting platforms with reference to first train's departure time whenever there's gap we decrease count ans set departure to next train's

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int count = 1, maxi = 1, i = 1, j = 0;
    while (i < n && j < n)
    {
        //* If there's break between j's dep and i's arrival we substrate jth train from count, We don't care about which train we just care about current count and we look this gap as one train departures so other can accommodate there
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        maxi = max(count, maxi);
    }
    return maxi;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}