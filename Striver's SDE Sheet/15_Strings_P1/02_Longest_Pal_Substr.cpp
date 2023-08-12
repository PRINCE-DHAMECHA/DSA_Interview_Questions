//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We start with middle and grow in both direction

string longestPalindrome(string s)
{
    int n = s.size();
    int palStart = 0, len = 1;
    //* Trying all possible middle
    for (int i = 0; i < n; i++)
    {
        int right = i;
        //* After this no matter whether we're checking for odd pal or even pal, it'll be same process
        //* Fact that even length pal has middle two characters same, so we're skipping them
        while (right < n && s[i] == s[right])
        {
            right++;
        }
        int left = i - 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (right - left - 1 > len)
        {
            len = right - left - 1;
            palStart = left + 1;
        }
    }
    return s.substr(palStart, len);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}