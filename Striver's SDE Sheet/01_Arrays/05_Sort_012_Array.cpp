//& Sort given array with only 0,1 and 2.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void sortColors(vector<int> &nums)
{
    //* We divide given array in three part with 3 index.
    //* Low will indicates next 0 to be insert and high indicates next 2 to be insert
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        //* if mid will be zero then we replace it with next zero position
        if (nums[mid] == 0)
        {
            swap(nums[low++], nums[mid++]);
        }
        //* If we encounter 1 we'll not do anything
        else if (nums[mid] == 1)
        {
            mid++;
        }
        //* If we encounter 2 we'll swap with high
        //! We won't increase mid as high can be 0 also, if it is then in next iteration we can swap it with low but if we increase mid then we just can't
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}