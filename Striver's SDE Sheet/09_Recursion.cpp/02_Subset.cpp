//& Return all subsets of given array which contains repetitions.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* We create set to avoid repetitions

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int max = pow(2, nums.size());
    set<vector<int>> allSubsets;
    for (int i = 0; i < max; i++)
    {
        int temp = i;
        vector<int> subset;
        for (int j = nums.size() - 1; j >= 0; j--)
        {
            if (temp & 1)
            {
                subset.push_back(nums[j]);
            }
            temp = temp >> 1;
        }
        sort(subset.begin(), subset.end());
        allSubsets.insert(subset);
    }
    vector<vector<int>> ans;
    for (auto i : allSubsets)
    {
        ans.push_back(i);
    }
    return ans;
}

//~ Approach:2 :-
//* Without set
//* We sort given nums and compare previous one before adding to answer to avoid duplicity

void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        //* If repetitions are there in this recursive call
        //* Repetitions will be allowed across the recursive calls but not allowed in particular recursive call
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ds, ans);
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}