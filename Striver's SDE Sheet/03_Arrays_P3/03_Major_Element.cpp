//& Find element in given n size array with frequency greater than N/2

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We take advantage of fact that after some extent if we encounter same number of other element as our major element, We know that in remaining part our major needs to be major otherwise it can't be major
//* So we try to narrow down continuously whenever we encounter count=0

int majorityElement(vector<int> &nums)
{
    //* Take initially first element as major
    int majorEle = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        //* Condition when we encouter other element count as our major element count
        //* We start with current element
        if (count == 0)
        {
            majorEle = nums[i];
            count++;
        }
        //* If we encounter major element, we increase count
        else if (majorEle == nums[i])
        {
            count++;
        }
        //* Otherwise for anyother number we'll decrease count
        else
        {
            count--;
        }
    }
    return majorEle;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}