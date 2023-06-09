//& Write a function to find the maximum for each and every contiguous subarray of size k.

//~ Input: N = 9, K = 3 arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}
//~ Output: {3, 3, 4, 5, 5, 5, 6}

//& Explanation: In the first subarray of size 3: {1,2,3}, the value 3 is maximum, similarly for all such subarrays for size 3.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//! Remaining
vector<int> maxOfSubArray(vector<int> v, int k)
{
    int n = v.size();
    int i = 0, j = 0;
    deque<int> dq;
    dq.push_front(i++);
    while (i < k)
    {
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i++);
        for (auto i : dq)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    vector<int> ans;
    while (i < n)
    {
        ans.push_back(v[dq.front()]);
        while (!dq.empty() && j >= dq.front())
        {
            dq.pop_front();
        }
        j++;
        while (!dq.empty() && v[dq.back()] <= v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i++);
    }
    ans.push_back(v[dq.front()]);
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> v = {1, 7, 3, 6, 4, 2, 6, 12, 5, 3, 6, 7};
    vector<int> ans = maxOfSubArray(v, 4);
    // for (auto i : ans)
    // {
    //     cout << i << endl;
    // }
    return 0;
}