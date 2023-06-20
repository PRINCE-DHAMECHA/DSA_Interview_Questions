//& Given array of distinct integers find unique combinations of numbers such that sum of it will be target.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use previous approach for finding subsets

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int target)
{
    //* All integers are positive so we return if target will be negative
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    if (ind >= nums.size())
    {
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        //* We'll not increase index as repetition is allowed
        findSubsets(i, nums, ds, ans, target - nums[i]);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans, target);
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}