//& Find maximum subArray with zero sum

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* We note prefix sum and if sum appears again then we know that intermediate elements sum up to 0 :)

int maxLen(vector<int> &nums, int n)
{
    map<int, int> mp;
    int sum = 0, maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (nums[i] == 0 && maxi == 0)
        {
            maxi = 1;
        }
        //* If sum becomes zero then no doubt the longest length will be till that index
        if (sum == 0)
        {
            maxi = i + 1;
        }
        //* If sum appears again
        if (mp.find(sum) != mp.end())
        {
            //* As we are storing index of sum we can get length with it
            maxi = max(maxi, i - mp[sum]);
        }
        //* Else store index
        else
        {
            mp[sum] = i;
        }
    }
    return maxi;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}