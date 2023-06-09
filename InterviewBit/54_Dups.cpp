//& Write a function to determine whether duplicate elements in a given array are within a given distance of each other.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Maintain hashmap which stores count at check nums repeat in given range or not and when interval exceeds given range we erase first element of given range

bool checkDups(vector<int> nums, int range)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        //* Remove out of the range element
        if (i >= range)
        {
            mp[nums[i - range]]--;
        }
        //* If count of current element is not zero still after remove out of the range element then  we got repetition
        if (mp[nums[i]] != 0)
        {
            return true;
        }
        //* Else increase count to 1
        mp[nums[i]]++;
    }
    return false;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << checkDups({1, 2, 3, 4, 2, 1, 2}, 3) << endl;
    return 0;
}