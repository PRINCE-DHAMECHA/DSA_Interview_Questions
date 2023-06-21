//& There is a new barn with N stalls and C cows. The stalls are located on a straight line at positions x1,….,xN (0 <= xi <= 1,000,000,000). We want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Approach will be same as previous problem
//* We first find search space then try to reduce it to get answer using binary search
//* Search space will be min= min possible gap, max= last- first (in sorted)

//* If we can have k cows in given minimum distance i.e. a
bool isValid(vector<int> &arr, int k, int a)
{
    int n = arr.size();
    int prev = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        //* If distance will be greater than equal to a then we can now add new cow
        if (arr[i] - prev >= a)
        {
            cnt++;
            prev = arr[i];
        }
    }
    //* If we can add atleast k cows
    return cnt >= k;
}

int aggressiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int mini = INT_MAX;
    int maxi = arr[n - 1] - arr[0];
    for (int i = 1; i < n; i++)
    {
        mini = min(mini, arr[i] - arr[i - 1]);
    }
    //* Search Space
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        //* If this mid is valid then we find greater answer than mid
        if (isValid(arr, k, mid))
        {
            low = mid + 1;
        }
        //* Else we reduce
        else
        {
            high = mid - 1;
        }
    }
    //* We need minimum and low will be at first wrong value so it's previous will be our answer
    return low - 1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}