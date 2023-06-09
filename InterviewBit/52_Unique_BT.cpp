//& Write a function to find number of structurally unique binary trees are possible.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* There will be 2nCn/(n+1) unique binary trees are there

//* Finding nCk
long binCoff(long n, long k)
{
    long res = 1;
    if (k > n - k)
    {
        k = n - k;
    }
    for (long i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

long catalanNum(long n)
{
    long C = binCoff(2 * n, n);
    return C / (n + 1);
}

long numOfUniqueBT(int n)
{
    return catalanNum(n);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << numOfUniqueBT(3) << endl;
    return 0;
}