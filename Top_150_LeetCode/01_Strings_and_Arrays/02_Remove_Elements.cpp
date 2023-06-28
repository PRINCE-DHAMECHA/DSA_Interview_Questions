//& Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Two Pointers

int removeElement(vector<int> &nums, int val)
{
    //* J will always points to next slot for unnecessary element
    //* Means using j we will append vals to end
    int i = 0, j = nums.size() - 1;
    while (i <= j)
    {
        //* If val occur then we push it to end pointed by j and decrease j
        //! Note that we'll not increase i as i can be val even after swap
        if (nums[i] == val)
        {
            swap(nums[i], nums[j--]);
        }
        else
        {
            i++;
        }
    }
    return i;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}