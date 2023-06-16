//& find all four distinct element which sum up to given target.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1
//* DP: TLE :)

void DP(vector<int> &nums, int target, vector<int> v, int n, set<vector<int>> &res)
{
    if (n == 0 || v.size() == 4)
    {
        int temp = target;
        for (auto i : v)
        {
            temp -= i;
        }
        if (temp == 0 && v.size() == 4)
        {
            sort(v.begin(), v.end());
            res.insert(v);
        }
        return;
    }
    DP(nums, target, v, n - 1, res);
    if (v.size() < 4)
    {
        v.push_back(nums[n - 1]);
        DP(nums, target, v, n - 1, res);
    }
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<vector<int>> res;
    vector<vector<int>> ans;
    DP(nums, target, {}, nums.size(), res);
    for (auto i : res)
    {
        ans.push_back(i);
    }
    return ans;
}

//~ Approach:2
//* Nested for loop :)

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<long> st;
    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                long rem = target - ((long)nums[i] + nums[j] + nums[k]);
                if (st.count(rem))
                {
                    vector<int> v = {nums[i], nums[j], nums[k], (int)rem};
                    sort(v.begin(), v.end());
                    s.insert(v);
                }
            }
        }
        //* Writing insert statement in outer loop is necessary to avoid reparations
        st.insert(nums[i]);
    }
    vector<vector<int>> res;
    for (auto i : s)
    {
        res.push_back(i);
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}