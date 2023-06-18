//& Remove duplicates in place means first k elements should be distinct after swapping and return k
//^ Given array is in sorted order

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* We keep one index var which points to the place where next element will be inserted in non repeating manner

int removeDuplicates(vector<int> &nums)
{
    //* First element will be there so start with 1
    int index = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        //* If current is not equal to prev means first appearance of curr so we place it at index
        if (nums[i] != nums[i - 1])
        {
            nums[index++] = nums[i];
        }
    }
    return index;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}