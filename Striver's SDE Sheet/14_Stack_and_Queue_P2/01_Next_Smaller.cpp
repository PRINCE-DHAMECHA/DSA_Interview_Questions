//& Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* We'll use same approach as we used for next greater but here's twist, Element are not distinct so we can't rely on just map with int value, So we'll use vector with it.

vector<int> prevSmaller(vector<int> &arr)
{
    stack<int> st;
    vector<int> res(arr.size(), -1);
    map<int, vector<int>> mp;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && st.top() > arr[i])
        {
            //* We push it starting from end so when we pop from starting we'll take last element in vector
            mp[st.top()].push_back(arr[i]);
            st.pop();
        }
        st.push(arr[i]);
    }
    //* We need to assign -1 to remaining element explicitly because repetitions are there so if later element doesn't have smaller element but starting element has then in for loop we assign element which doesn't have smaller
    while (st.size())
    {
        mp[st.top()].push_back(-1);
        st.pop();
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp[arr[i]].size())
        {
            res[i] = mp[arr[i]][mp[arr[i]].size() - 1];
            mp[arr[i]].pop_back();
        }
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}