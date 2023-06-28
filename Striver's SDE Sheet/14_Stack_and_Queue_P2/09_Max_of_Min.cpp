//& Find maximum of minimum of every size subarrays.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We find left and right smaller array
//* Then we try every length of array of this subarrays and update our answer array
//* The from back we fill unfilled array
vector<int> maxMinWindow(vector<int> a, int n)
{
    stack<int> s;
    vector<int> leftSmall(n, -1), rightSmall(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and a[s.top()] >= a[i])
            s.pop();
        if (!s.empty())
            leftSmall[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
    {
        s.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and a[s.top()] >= a[i])
            s.pop();
        if (!s.empty())
            rightSmall[i] = s.top();
        s.push(i);
    }
    vector<int> ans(n, INT_MIN), res(n);
    for (int i = 0; i < n; i++)
    {
        int len = rightSmall[i] - leftSmall[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }
    cout << endl;
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i - 1] = max(ans[i - 1], ans[i]);
    }

    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}