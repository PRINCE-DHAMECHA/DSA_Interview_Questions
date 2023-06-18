//& Find 3 distinct numbers which sum up to 0.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We sort and loop over all element and find 0-current in remaining array with traditional 2Sum which is already sorted.

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0 || (i != 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1, high = nums.size() - 1, target = 0 - nums[i];
            cout << nums[i] << " " << target << endl;
            while (low < high)
            {
                if (nums[low] + nums[high] < target)
                {
                    low++;
                }
                else if (nums[low] + nums[high] > target)
                {
                    high--;
                }
                else
                {
                    cout << target << endl;
                    s.insert({0 - target, nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
    }
    for (auto i : s)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}