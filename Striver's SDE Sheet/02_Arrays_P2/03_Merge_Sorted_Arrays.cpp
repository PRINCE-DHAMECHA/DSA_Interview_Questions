//& Merge given 2 arrays in first array which has capacity to hold second array's element

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We start from end of first array and start inserting elements from the end of two arrays.
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int total = m + n - 1, ind1 = m - 1, ind2 = n - 1;
    while (ind1 >= 0 && ind2 >= 0)
    {
        if (nums1[ind1] > nums2[ind2])
        {
            nums1[total--] = nums1[ind1--];
        }
        else
        {
            nums1[total--] = nums2[ind2--];
        }
    }
    while (ind2 >= 0)
    {
        nums1[total--] = nums2[ind2--];
    }
    //* We can avoid loop for ind1 as it will be already there
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}