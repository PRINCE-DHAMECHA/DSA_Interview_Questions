//& Follow up of 04: Find missing and repeating number in given n element array

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* sum(arr[0...n-1]) - sum(1....n) = dup - missing
//* sum(arr[0...n-1]^2) - sum(1....n^2) = dup^2 - missing^2
//* dup+missing= (dup^2 - missing^2) / (dup - missing)
//* Now we can find dup and missing

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();

    //* sum(arr[0...n-1])
    long long SN = (n * (n + 1)) / 2;
    //* sum(arr[0...n-1]^2)
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        //* sum(1....n)
        S += a[i];
        //* sum(1....n^2)
        S2 += (long long)a[i] * (long long)a[i];
    }

    //* dup - missing
    long long val1 = S - SN;

    //* dup^2 - missing^2
    long long val2 = S2 - S2N;

    //* dup+missing
    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}