//& Find longest continuos sequence in O(n)

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Using map we store intervals

int longestConsecutive(vector<int> &nums)
{
    map<int, int> mp;
    int res = 0;
    for (auto i : nums)
    {
        //* If element is not in map then only we proceed
        //* To avoid reparations
        if (mp.find(i) == mp.end())
        {
            //* Find count of subsequence in left number
            int left = mp.find(i - 1) != mp.end() ? mp[i - 1] : 0;
            //* Find count of subsequence in right number
            int right = mp.find(i + 1) != mp.end() ? mp[i + 1] : 0;
            //* Total sequence length
            int sum = left + right + 1;
            //* set sequence length of current number
            mp[i] = sum;
            res = max(res, sum);
            //* Set sequence length of left most element
            mp[i - left] = sum;
            //* Also set it in rightmost element
            mp[i + right] = sum;
        }
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}