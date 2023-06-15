//& Find element with frequency greater than N/3 in given n size array with frequency greater than N/2

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We know that there will be at most 2 such element as it's strictly greater than N/3
//* We use previous approach but this time we maintain two counter as below

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int ele1 = INT_MIN, ele2 = INT_MIN, count1 = 0, count2 = 0;
    //* This approach works because when we increase count of suppose count1, we're not decreasing count2 and vice-versa
    for (int i = 0; i < nums.size(); i++)
    {
        if (count1 == 0 && ele2 != nums[i])
        {
            ele1 = nums[i];
            count1++;
        }
        else if (count2 == 0 && ele1 != nums[i])
        {
            ele2 = nums[i];
            count2++;
        }
        else if (ele1 == nums[i])
        {
            count1++;
        }
        else if (ele2 == nums[i])
        {
            count2++;
        }
        else
        {
            count1--, count2--;
        }
    }
    //* We need to double check because we can't rely on last count as it can be less than N/3 also because we are decreasing count in non major one
    count1 = 0, count2 = 0;
    for (auto i : nums)
    {
        if (i == ele1)
        {
            count1++;
        }
        if (i == ele2)
        {
            count2++;
        }
    }
    vector<int> res;
    if (count1 > n / 3)
    {
        res.push_back(ele1);
    }
    if (count2 > n / 3)
    {
        res.push_back(ele2);
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}