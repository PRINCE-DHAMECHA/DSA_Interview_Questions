//& Question: Write a method to return all subsets of a set.

//^ Solution:
//? Time And Space Complexities= O(n2^n)

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* How you get subsets of {a,b,c} using subset of {a,b}?
vector<vector<int>> allSubsetsRec(vector<int> set, int i)
{
    vector<vector<int>> subsets;
    if (i == 0)
    {
        subsets.push_back({});
        subsets.push_back({set[i]});
        return subsets;
    }
    else
    {
        subsets = allSubsetsRec(set, i - 1);
        int size = subsets.size();
        for (int j = 0; j < size; j++)
        {
            vector<int> tempSubset = subsets[j];
            tempSubset.push_back(set[i]);
            subsets.push_back(tempSubset);
        }
        return subsets;
    }
}

//* Element can be there or cannot be there, So we need to consider all possible yes/on sequence so that we can create all subsets
//* sequence of yes/no is nothing but binary number from 0 to 2^n
vector<vector<int>> allSubsetsIterative(vector<int> set)
{
    int max = pow(2, set.size());
    vector<vector<int>> allSubsets;
    for (int i = 0; i < max; i++)
    {
        int temp = i;
        vector<int> subset;
        for (int j = set.size() - 1; j >= 0; j--)
        {
            if (temp & 1)
            {
                subset.push_back(set[j]);
            }
            temp = temp >> 1;
        }
        reverse(subset.begin(), subset.end());
        allSubsets.push_back(subset);
    }
    return allSubsets;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<vector<int>> mySubsetsRec = allSubsetsRec({1, 2, 2, 3}, 3);
    for (auto i : mySubsetsRec)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    vector<vector<int>> mySubsetsIterative = allSubsetsIterative({1, 2, 2, 3});
    for (auto i : mySubsetsIterative)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}