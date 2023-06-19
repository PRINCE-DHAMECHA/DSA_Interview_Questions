//& Given denominator of 1,2,5,10,20,50,100,500 and 1000 find minimum coins needed to exchange given amount.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* Start greedily from biggest denominator

//* Greedy approach doesn't give optimal answer for all
int findMinimumCoins(int amount)
{
    vector<int> v = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int count = 0, i = v.size() - 1;
    while (amount > 0)
    {
        if (amount < v[i])
        {
            i--;
        }
        else
        {
            amount -= v[i];
            count++;
        }
    }
    return count;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}