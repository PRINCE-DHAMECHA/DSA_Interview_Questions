//& Convert given number roman to english numerical.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* In roman sometime bigger will be after smaller like 'IV' so we need to subtract previous from after
//* So we iterate from end and subtract or add as required.
int romanToInt(string s)
{
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int ans = 0, prev = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int num = mp[s[i]];
        if (num < prev)
        {
            ans -= num;
        }
        else
        {
            ans += num;
        }
        prev = num;
    }
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}