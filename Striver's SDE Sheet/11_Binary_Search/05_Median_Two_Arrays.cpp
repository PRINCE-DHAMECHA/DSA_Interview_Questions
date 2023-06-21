//& Find median of given two sorted arrays.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We try to make partitions using binary search
//* Wx:- 1 2 4 8   and  2 7 9 10 then we can part in 1 , 2 7 and 2 4 8 , 9 10
//* Then we compare max of first to min of two and vice versa for valid partition
//* We make partition such that left side will have total/2 elements so max of left will be median for odd and avg. of left max and right min will be median for even

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    //* Making sure that we do binary search in smaller one
    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    int n1 = nums1.size();
    int n2 = nums2.size();
    int target = (n1 + n2 + 1) / 2;
    //* Possible partition
    //* Low means no first array element and high means all first array elements
    int low = 0, high = n1;
    while (low <= high)
    {
        //* Finding median of first
        int cut1 = (high + low) / 2;
        //* Taking remaining from second
        int cut2 = target - cut1;
        //* Deciding left and right mins
        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
        //* If partition is valid
        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2)
            {
                return max(left1, left2);
            }
            else
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
        }
        //* Left max is bigger than right min so we decrease left min
        if (left1 > right2)
        {
            high = cut1 - 1;
        }
        //* Vice versa
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}