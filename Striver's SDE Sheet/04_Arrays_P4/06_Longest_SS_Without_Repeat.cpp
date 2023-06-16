//& Find longest substring without repetitions

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use set to maintain elements and check all characters whether its in set or not, If it is then we remove until the repetition will gone
int lengthOfLongestSubstring(string s)
{
    unordered_set<char> set;

    int i = 0, j = 0, n = s.size(), res = 0;

    while (i < n && j < n)
    {
        if (set.find(s[j]) == set.end())
        {
            set.insert(s[j++]);
            res = max(res, j - i);
        }
        else
        {
            set.erase(s[i++]);
        }
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}