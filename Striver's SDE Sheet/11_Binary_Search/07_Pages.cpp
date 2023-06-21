//& The College library has N bags, the ith book has A[i] number of pages. You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in contiguous order, for example, A student cannot be allocated book 1 and book 3, skipping book 2. Calculate and return the minimum possible number. Return -1 if a valid assignment is not possible.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We can have sorted search space by deciding min and max ans.
//* Minimum will be maximum of all pages and maximum will be sum of all pages.
//* Now we try mid of them and check whether we can assign in this range or not.
//* Like if mid is 100 then we check that can we assign pages such that answer can be less than 100 by given students. If we req. more students then we increase low otherwise decrease high.

bool isValid(int n, int m, vector<int> time, long long a)
{
    int cnt = 0;
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        //* If sum exceed then we need more student
        if (sum + time[i] <= a)
        {
            sum += time[i];
        }
        else
        {
            cnt++;
            sum = time[i];
        }
    }
    //* If we can accommodate in given student then return true
    return cnt < n;
}

long long minPages(int n, int m, vector<int> time)
{
    long long sum = 0;
    int maxi = 0;
    for (auto i : time)
    {
        sum += i;
        maxi = max(maxi, i);
    }
    long long low = maxi, high = sum;
    while (low <= high)
    {
        long long mid = (low + (high - low) / 2);
        //* If it's valid then reduce to left side
        if (isValid(n, m, time, mid))
        {
            high = mid - 1;
        }
        //* Other wise right side
        else
        {
            low = mid + 1;
        }
    }
    //* Low>High means this is minimum possible low such that we give pages in optimal way
    return low;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}