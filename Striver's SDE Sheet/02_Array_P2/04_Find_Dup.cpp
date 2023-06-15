//& given array of n+1 size which contains elements from 1 to n find repeating number.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Binary search (pigeon hole)

int findDuplicate(vector<int> &nums)
{
    int low = 1, high = nums.size();
    while (low < high)
    {
        //* take mid
        int mid = low + ((high - low) / 2);
        int cnt = 0;
        //* count element less than or equal to mid
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                cnt++;
            }
        }
        //* If count greater than or equal to mid means repeating in left side
        if (cnt <= mid)
        {
            low = mid + 1;
        }
        //* Otherwise right side
        else
        {
            high = mid;
        }
    }
    //* High or low both fine
    return low;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}