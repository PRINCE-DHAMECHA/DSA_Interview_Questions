//& Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

//& If such an arrangement is not possible, it must rearrange to the lowest possible order(i.e., sorted in ascending order).

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We start from end and find bigger element than current one in right side and select minimum of it and swap it with current one and then we sort right side
void nextPermutation(vector<int> &nums)
{
    int ourIndex = -1;
    //* Store index of right side elements
    vector<int> v(101, -1);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        bool flag = false;
        //* If there exist bigger element than current one
        //* First one will be smaller in right side because we start from current+1 and going to 100
        for (int j = nums[i] + 1; j <= 100; j++)
        {
            if (v[j] != -1)
            {
                swap(nums[i], nums[v[j]]);
                //* ourIndex indicates from where we need to sort array because after swapping we will sort remaining array
                ourIndex = i + 1;
                flag = true;
                break;
            }
        }
        v[nums[i]] = i;
        if (flag)
        {
            break;
        }
    }
    //* If ourIndex is not zero means next lex. order is not possible we just sort whole array
    if (ourIndex == -1)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    sort(nums.begin() + ourIndex, nums.end());
    return;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}