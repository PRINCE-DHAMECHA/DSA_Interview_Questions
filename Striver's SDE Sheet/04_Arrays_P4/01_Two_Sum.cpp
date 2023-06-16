//& Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* Two pointer

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < nums.size(); i++)
    {
        vp.push_back({nums[i], i});
    }
    sort(vp.begin(), vp.end());
    int l = 0, r = vp.size() - 1;
    while (1)
    {
        if (vp[l].first + vp[r].first == target)
        {
            vector<int> v;
            v.push_back(vp[l].second);
            v.push_back(vp[r].second);
            return v;
        }
        if (vp[l].first + vp[r].first > target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    vector<int> v;
    return v;
}

//~ Approach:2
//* Using hashMap

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mp;
    int rem;
    for (int i = 0; i < nums.size(); i++)
    {
        rem = target - nums[i];
        if (mp.find(rem) != mp.end())
        {
            return {i, mp[rem]};
        }
        mp[nums[i]] = i;
    }
    return {-1};
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}