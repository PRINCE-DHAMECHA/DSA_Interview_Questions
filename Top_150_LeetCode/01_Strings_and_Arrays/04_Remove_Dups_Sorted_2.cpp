//& Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* i will iterate through list and j will point to next index where we push unnecessary repeating elements from end
//* To keep track of occurrences we'll use map

int removeDuplicates(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    map<int, int> mp;
    //* When we cross j then all element will be unnecessary and we return i which indicates size of necessary elements
    while (i <= j)
    {
        //* If unnecessary element found then swap with last elements
        if (mp[nums[i]] == 2)
        {
            swap(nums[i], nums[j--]);
        }
        else
        {
            mp[nums[i]]++;
            i++;
        }
    }
    //* As we need to maintain relative order we'll sort array
    sort(nums.begin(), nums.begin() + i);
    return i;
}

//~ Approach:2 :-
//* We create variable i which points to next valid index means before that all element is occurring at most twice
//* Now if we compare jth element with (i-2)th and if that's less than or equal to (i-2)th element means there's repetition of more than two element so we don't push that number to ith place

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (auto num : nums)
    {
        if (i < 2 || num > nums[i - 2])
        {
            nums[i++] = num;
        }
    }
    return i;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}