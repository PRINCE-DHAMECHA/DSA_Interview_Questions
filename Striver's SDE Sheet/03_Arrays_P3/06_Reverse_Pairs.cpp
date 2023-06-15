//& Given an integer array nums, return the number of reverse pairs in the array.

//& A reverse pair is a pair (i, j) where:

//^ 0 <= i < j < nums.length and
//^ nums[i] > 2 * nums[j].

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use the same approach as in 02/06_Count_Inversions
//* But here the only difference is that we can't use merge function to count pairs because it has different condition and we can't change that
//* So we need one function to calculate pair count before merge

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] / 2.0 > arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    //* Only change need to done
    //* We count pairs using two pointer for two sorted array
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}