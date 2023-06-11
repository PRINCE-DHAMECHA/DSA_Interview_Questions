//& Find given string in given sorted array of string which also contains empty string.

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
//* We need to modify binary search slightly.
//* If mid element will be "" then we find closest non empty string and take that as mid to compare.

int search(vector<string> &v, int low, int high, string key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == key)
        {
            return mid;
        }
        if (v[mid] == "")
        {
            //* Start with next and prev index of mid and traverse both side until we find non empty string in given bound
            int left = mid - 1, right = mid + 1;
            while (1)
            {
                //* If we cross the bound return -1 as there will be no key exist
                if (left < low && right > high)
                {
                    return -1;
                }
                else if (right <= high && v[right] != "")
                {
                    mid = right;
                    break;
                }
                else if (left >= low && v[left] != "")
                {
                    mid = left;
                    break;
                }
                right++;
                left--;
            }
        }
        //* Traditional Binary Search
        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] < key)
        {
            return search(v, mid + 1, high, key);
        }
        else
        {
            return search(v, low, mid - 1, key);
        }
    }
    return -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<string> v = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << search(v, 0, v.size() - 1, "ball") << endl;
    cout << search(v, 0, v.size() - 1, "at") << endl;
    return 0;
}