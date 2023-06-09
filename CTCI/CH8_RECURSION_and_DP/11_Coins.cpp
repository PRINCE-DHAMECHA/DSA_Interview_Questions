//& Question: Given an infinite number of given coins, Write algorithm to find number of ways to making change of n rupees.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

vector<vector<int>> MEM(1000, vector<int>(1000, -1));

//~ Approach:
//* v={25,10,5,1} // start from 25
//* makeChange(100)= makechange(100 using 0 25s) + makechange(100 using 1 25s) + makechange(100 using 2 25s) + makechange(100 using 3 25s) + makechange(100 using 4 25s)
//* makeChange(100 using 4 25s) is 1 ways

int makeChange(int n, vector<int> v, int index)
{
    if (MEM[n][index] != -1)
    {
        return MEM[n][index];
    }
    if (index == v.size() - 1)
    {
        return !(n % v[index]);
    }
    int denom = v[index];
    int ways = 0;
    for (int i = 0; i * denom <= n; i++)
    {
        int rem = n - (i * denom);
        ways += makeChange(rem, v, index + 1);
    }
    return MEM[n][index] = ways;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> v = {25, 10, 5};
    int n = 100;
    cout << makeChange(n, v, 0) << endl;

    return 0;
}