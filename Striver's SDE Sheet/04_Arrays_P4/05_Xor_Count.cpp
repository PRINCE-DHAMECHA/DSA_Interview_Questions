//& Count subset which result in given number after XOR.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Based on the fact that if A^C=B then A^B=C
//*so we find continuously find xor and when xorr^target already have been previous then we find count of it and add to ans
int solve(vector<int> &A, int B)
{
    int cnt = 0, xorr = 0;
    map<int, int> mp;
    for (int i = 0; i < A.size(); i++)
    {
        xorr ^= A[i];
        if (xorr == B)
        {
            cnt++;
        }
        if (mp.find(xorr ^ B) != mp.end())
        {
            cnt += mp[xorr ^ B];
        }
        mp[xorr]++;
    }
    return cnt;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}