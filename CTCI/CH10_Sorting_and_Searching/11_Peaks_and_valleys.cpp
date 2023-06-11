//& Question: peak is when the element in array is bigger than it's neighbour and vice versa for valley. Given array of integers, make array as alternate sequence of peaks and valleys.

//^ Solution

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Sort given array and then make changes according.
//* small -> medium -> large ==> medium -> small -> large (skip 2 index now means move on to large and repeat)

void sortValleyPeak(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i += 2)
    {
        swap(nums[i], nums[i + 1]);
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> nums = {7, 9, 8, 4, 1, 0};
    sortValleyPeak(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}