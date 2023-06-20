//& consider array as [1,2,3,...,n].
//& Find Nth permutation.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use approach of 01-03_Permutation and run it k-1 times to get kth permutation for 1234..N

//* We start from end and find bigger element than current one in right side and select minimum of it and swap it with current one and then we sort right side
void nextPermutation(vector<int> &nums)
{
    int ourIndex = -1;
    //* Store index of right side elements
    vector<int> v(101, -1);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        bool flag = false;
        //* If there exist bigger element than current one
        //* First one will be smaller in right side because we start from current+1 and going to 100
        for (int j = nums[i] + 1; j <= 100; j++)
        {
            if (v[j] != -1)
            {
                swap(nums[i], nums[v[j]]);
                //* ourIndex indicates from where we need to sort array because after swapping we will sort remaining array
                ourIndex = i + 1;
                flag = true;
                break;
            }
        }
        v[nums[i]] = i;
        if (flag)
        {
            break;
        }
    }
    //* If ourIndex is not zero means next lex. order is not possible we just sort whole array
    if (ourIndex == -1)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    sort(nums.begin() + ourIndex, nums.end());
    return;
}
string getPermutation(int n, int k)
{
    int temp = 1;
    vector<int> nums;
    while (temp != n + 1)
    {
        nums.push_back(temp++);
    }
    k--;
    while (k--)
    {
        nextPermutation(nums);
    }
    string res;
    for (auto i : nums)
    {
        res += i + '0';
    }
    return res;
}

//~ Approach:2 :-
//* Suppose we take N=4 then there's 24 permutation and for 0 to 5 1 will be at first place and 6 to 11 2 will be first place
//* So we set each bits from starting

string getPermutation(int n, int k)
{
    vector<pair<int, bool>> vp;
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        vp.push_back({i, true});
        fact *= i;
    }
    int size = n;
    string res;
    k--;
    for (int i = 0; i < n; i++)
    {
        //* We get 6 in first round to decide intervals
        fact /= size;
        //* Which number will be our first one means if it's 0 then at first place there will be 1
        int index = k / fact;
        //* If sum intermediate number is taken and in next round we need to find ith number then we check bool
        //* If bool=true means element yet to place and vice versa
        int count = -1, j = -1;
        while (j < n && count != index)
        {
            j++;
            if (vp[j].second == true)
            {
                count++;
            }
        }
        //* Now the permutation will be reduce
        k = k % fact;
        //* We append the number
        res += vp[j].first + '0';
        //* Make appended element as false to not take it again
        vp[j].second = false;
        //* Now the size will be decreased for deciding factors
        size--;
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}