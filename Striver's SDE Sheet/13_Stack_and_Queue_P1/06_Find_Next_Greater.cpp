//& Find next greater element from right side for all given elements in nums1;
//& nums1 is subset of nums2

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We'll use stack
//* We start from  beginning and add element in stack which next greater min is yet to find
//* When we add element we pop all element in stack which will have next greater as current and then we add current to find it's next greater

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res(nums1.size(), -1);
    map<int, int> mp;
    stack<int> st;
    for (auto num : nums2)
    {
        //* Pop until current is greater than stack element because element of stack doesn't have next greater and current can be it's next greater
        while (st.size() != 0 && st.top() < num)
        {
            mp[st.top()] = num;
            st.pop();
        }
        //* Push current to find it's next greater
        st.push(num);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (mp[nums1[i]])
        {
            res[i] = mp[nums1[i]];
        }
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}