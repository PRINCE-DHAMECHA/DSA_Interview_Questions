//& Find maximum in each subArrays.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We maintain decreasing order of element in given intervals using dequeue and pop front whenever exceeds range of k

//^ Implementation:1 :- Accepted in Coding Ninja and TLE in LeetCode :)
vector<int> maxSlidingWindow(vector<int> &v, int k)
{
    int n = v.size();
    int i = 0, j = 0;
    deque<int> dq;
    dq.push_front(i++);
    while (i < k)
    {
        //* Till kth element we maintain decreasing order in our deque
        //* So front will be our biggest element in this k element
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
        //* We push front to answer because it's biggest
        ans.push_back(v[dq.front()]);
        //* Now to take care of boundary we need to also pop from front when front is out of range
        //* Means for first iteration if we insert k+1th element we need to remove front if it's 0
        //* So we start from j=0
        while (!dq.empty() && j >= dq.front())
        {
            dq.pop_front();
        }
        j++;
        //* Now again we maintain decreasing order
        while (!dq.empty() && v[dq.back()] <= v[i])
        {
            dq.pop_back();
        }
        //* And then we push our index
        dq.push_back(i++);
    }
    ans.push_back(v[dq.front()]);
    return ans;
}

//^ Implementation:2 :- Accepted in LeetCode

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        //* When front is out of range
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        //* Maintain decreasing order before inserting new element
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        //* Start inserting maximum after we process k element means when we reach k-1 because for k-1 we already processed that index
        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}