//& Write a function to find number of subArrays with product strictly less than K.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

int NumSubArrayKProd(vector<int> nums, int k)
{
    int ans = 0;
    int prod = 1;
    int left = 0, right = 0;
    while (right < nums.size())
    {
        prod *= nums[right];
        //* We make left and right such that its product will be <k and now we can consider all subset including right because all subset before right will be consider in prior iterations
        while (prod >= k && left <= right)
        {
            prod /= nums[left++];
        }
        //? How to count all subset including right?
        //* consider we add 4 in {1,2,3} so now we have {1,2,3,4} and total  number of subset includes 4 will be right-left+1 i.e. 3-0+1 = 4 which is {1,2,3,4} {2,3,4} {3,4} {4}
        ans += right - left + 1;
        right++;
    }
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << NumSubArrayKProd({1, 6, 2, 3, 2, 1}, 12) << endl;
    return 0;
}