//& Merge given k arrays.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Priority Queue

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : kArrays)
    {
        for (auto j : i)
        {
            pq.push(j);
        }
    }
    while (pq.size())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}