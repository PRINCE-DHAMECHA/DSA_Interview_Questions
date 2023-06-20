//& Generate all permutation of given number array.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* If we have permutation of bca then we have permutation of bcad by inserting d in all possible position in all position

vector<vector<int>> permute(vector<int> &nums, int index = 0)
{
    vector<vector<int>> allPerms;
    if (index == nums.size() - 1)
    {
        return {{nums[nums.size() - 1]}};
    }
    //* Finding remaining characters permutation recursively
    vector<vector<int>> allRemPerms = permute(nums, index + 1);
    //* All permutation
    for (auto i : allRemPerms)
    {
        //* All possible places
        for (int j = 0; j <= i.size(); j++)
        {
            vector<int> temp = i;
            temp.insert(temp.begin() + j, nums[index]);
            allPerms.push_back(temp);
        }
    }
    return allPerms;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}