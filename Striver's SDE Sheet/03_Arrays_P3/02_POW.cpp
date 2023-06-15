//& Implement power function

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Square and Multiply

double myPow(double x, int n)
{
    double t = 1L;
    long long nn = n;
    nn = nn < 0 ? nn * -1 : nn;
    while (nn > 0)
    {
        if (nn % 2 != 0)
        {
            t = (t * x);
        }
        x = (x * x);
        nn /= 2;
    }
    return n < 0 ? 1 / t : t;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}