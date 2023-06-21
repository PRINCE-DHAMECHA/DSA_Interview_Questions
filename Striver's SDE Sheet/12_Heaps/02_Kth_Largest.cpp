//& Find Kth largest element of given array.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* We first add first k elements into priority queue with smallest as priority and then add element in queue if that's less than top of queue
//* This way we'll have k largest element in queue and we return top which is smallest means Kth largest

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    //* First add k element
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    //* Now remaining, So total element in queue will be always k
    for (int i = k; i < nums.size(); i++)
    {
        //* If smallest is smaller than current then add current and pop smallest
        if (pq.top() < nums[i])
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

//~ Approach:2 :-
//* We find position of pivot and then we use binary search to find position k-1

//* We find position of pivot and make bigger element left side of it and smaller to right side
int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (nums[j] > pivot)
        {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

//* Binary search to find k-1th position
int findKthLargest(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1;
    while (1)
    {
        int idx = partition(arr, left, right);
        //* If we have k-1 element on left side
        if (idx == k - 1)
        {
            return arr[idx];
        }
        //* If we've have less than k-1 element then our element will be right side
        if (idx < k - 1)
        {
            left = idx + 1;
        }
        //* Left side otherwise
        else
        {
            right = idx - 1;
        }
    }
    return -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}