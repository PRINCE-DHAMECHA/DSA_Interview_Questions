//& Given array with every element occurring twice except one. Your task? Find that imposter.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We binary search on the fact that every element occurring twice
//* 1 1 2 3 3 5 5
//* Here mid==mid+1 if our target is left side otherwise it's in right (odd left)
//* 1 1 2 2 3 3 5 6 6 vice versa (even left side)
//* In each iteration we make sure that elements between left and right will be odd including themselves

int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = ((low + high) / 2);
        //* Check according to count
        if (mid > 0 && mid < nums.size() - 1 && (mid - low) % 2 == 0 ? nums[mid - 1] == nums[mid] : nums[mid + 1] == nums[mid])
        {
            //* To make sure interval with odd length
            high = (mid - low) % 2 == 0 ? mid : mid - 1;
        }
        else
        {
            //* To make sure interval with odd length
            low = (mid - low) % 2 == 0 ? mid : mid + 1;
        }
    }
    return nums[low];
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}