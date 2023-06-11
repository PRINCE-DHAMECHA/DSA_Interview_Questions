//& Given sorted array but you can't access to it's size. given key find it's index in given array. If not exists return -1.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Use binary exponential backoff technique means start with 2 and check if 2nd index is greater than key or not and continue to 4 then 8....
//* Stop when you find greater element and do BS till that index because given array is sorted

int binarySearchRec(vector<int> &nums, int low, int high, int key)
{
    //* until low is less than or equal to high because high<low doesn't make any sense
    if (low <= high)
    {
        //* Find mid
        int mid = low + (high - low) / 2;
        //* Compare it with key
        if (nums[mid] == key)
        {
            return mid;
        }
        //* Key is in left side excluding mid
        if (nums[mid] > key)
        {
            return binarySearchRec(nums, low, mid - 1, key);
        }
        //* Key is in right side excluding mid
        else
        {
            return binarySearchRec(nums, mid + 1, high, key);
        }
    }
    //* Key not found
    return -1;
}

int search(vector<int> &nums, int key)
{
    int ind = 2;
    while (nums[ind] != -1 && nums[ind] < key)
    {
        ind *= 2;
    }
    return binarySearchRec(nums, ind / 2, ind, key);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> v = {1, 2, 2, 3, 4, 5, 13, 23, 28, 34, 342, 2342, -1, -1, -1, -1, -1, -1};
    cout << search(v, 2) << endl;
    cout << search(v, 23) << endl;
    cout << search(v, 50) << endl;
    cout << search(v, 5000) << endl;
    return 0;
}