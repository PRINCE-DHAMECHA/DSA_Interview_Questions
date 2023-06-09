//& Find the subsequence of length 3 with the highest product from a sequence of non-negative integers, with the elements in strictly increasing order.

//~ Input: n = 8 arr[ ] = {6, 7, 10, 1, 2, 3, 11, 12}
//~ Output: {10, 11, 12}

//&The three increasing elements of the given arrays are 10, 11, and 12, which form a three-size subsequence with the highest product.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

vector<int> maxProd(vector<int> a)
{
    int n = a.size();
    set<int> s;
    vector<int> smallerLeft(n);
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
        auto it = s.lower_bound(a[i]);
        //* Given set is ordered so if we insert element and find lower_bound then it'll stop at inserted element as it'll be our first equal element to a[i]
        //* Now if this will be not our first element then then there exist biggest smaller element then a[i] which is *(--it) or of it will be our first then no smaller element then our a[i] exist so we put -1
        if (it == s.begin())
        {
            smallerLeft[i] = -1;
        }
        else
        {
            it--;
            smallerLeft[i] = *it;
        }
    }
    cout << endl;
    int m = 0, p = INT_MIN;
    vector<int> res(3);
    res[0] = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        //* If a[i] is greater then m then we can't consider our previous m as it will be smaller so we'll consider this a[i] as m and search for next smaller
        if (a[i] >= m)
        {
            m = a[i];
        }
        //* We find smaller number then m on left side as we iterate in reverse order
        else
        {
            //* If there also exist smaller element than a[i] then we consider it and calculate maximum
            if (smallerLeft[i] != -1)
            {
                //* If found bette ans then change p ans update res and continue
                if (smallerLeft[i] * a[i] * m > p)
                {
                    p = smallerLeft[i] * a[i] * m;
                    res[0] = smallerLeft[i];
                    res[1] = a[i];
                    res[2] = m;
                }
            }
        }
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    for (auto i : maxProd({10, 1, 2, 3, 11, 12, 2, 3, 2, 1, 4, 5}))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}