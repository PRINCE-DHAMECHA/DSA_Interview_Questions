//& Given two array find k max sum by taking one element from each array.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We priority queue :)

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    vector<int> ans;
    priority_queue<int> pq;
    for (auto i : a)
    {
        for (auto j : b)
        {
            pq.push(i + j);
        }
    }
    while (k--)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}