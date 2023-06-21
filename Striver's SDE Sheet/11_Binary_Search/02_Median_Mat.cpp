//& Given matrix with sorted row find overall median.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* We can solve this easily by sorting all element and then return the middle one.

//~ Approach:2 :-
//* We use binary search to find median.
//* We start with 1 to 1e9 range and decrease the range to find our median as soon as we find break point in count we return

//* Function to count element less than or equal to current element
//* We try to find immediate next index of our element
//* Means when low will be more than high our low will point to immediate next and as array will be 0 indexed low will be number of element
//* Ex: 1 2 3 3 4 4 4 5 6 7  element=4 :- low=7 so there will be 7 element less than or equal to 5
int getCount(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        //* If element equal to x then there might be more element in right so we increase low
        if (arr[mid] <= x)
        {
            low = mid + 1;
        }
        //* Otherwise we'll decrease
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

//^ What is median?
//* Element which has half element on left side
//* We try to find breakpoint after which this count will change and out count will be half of total
//* So when the low changes from more than half count we'll have our median
//* We are doing BS in whole range and not just on elements of matrix but we'll have our answer in elements of matrix as we're finding that breakpoint because it's changing count it must be in matrix
int getMedian(vector<vector<int>> &matrix)
{
    int low = 1, high = 1e9;
    int sz = matrix.size() * matrix[0].size();
    while (low <= high)
    {
        int mid = (high + low) / 2;
        int cnt = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            cnt += getCount(matrix[i], mid);
        }
        //* Equal is necessary as we need exactly half at right side not including current one
        if (cnt <= (sz / 2))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}