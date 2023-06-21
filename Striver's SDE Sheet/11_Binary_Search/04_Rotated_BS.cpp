//& Search given key in given array which is sorted before rotating.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* At any mid we can say that either side will be sorted, so recurse accordingly.

int search(vector<int> v, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == key)
        {
            return mid;
        }
        //* Left part is sorted
        if (v[low] < v[mid])
        {
            //* If key lies in left part
            if (v[low] <= key && v[mid] > key)
            {
                return search(v, low, mid - 1, key);
            }
            else
            {
                return search(v, mid + 1, high, key);
            }
        }
        //* If right part is sorted
        if (v[mid] < v[low])
        {
            //* If key lies in right part
            if (v[mid] < key && v[high] >= key)
            {
                return search(v, mid + 1, high, key);
            }
            else
            {
                return search(v, low, mid - 1, key);
            }
        }
        //* Left side is all repeating value
        if (v[low] == v[mid])
        {
            //* If right side is different then search only right
            if (v[mid] != v[high])
            {
                return search(v, mid + 1, high, key);
            }
            //* Else search for both part
            else
            {
                int res = search(v, mid + 1, high, key);
                if (res == -1)
                {
                    return search(v, low, mid - 1, key);
                }
                else
                {
                    res;
                }
            }
        }
    }
    return -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> v = {44324, 45343, 45343, 50000, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 4, 5, 34, 342, 2342};
    cout << search(v, 0, v.size() - 1, 50000) << endl;
    return 0;
}
