//& Find k most frequent elements

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* Priority Queue :)

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto i : mp)
    {
        pq.push({i.second, i.first});
    }
    vector<int> res;
    while (k--)
    {
        auto i = pq.top();
        pq.pop();
        res.push_back(i.second);
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}