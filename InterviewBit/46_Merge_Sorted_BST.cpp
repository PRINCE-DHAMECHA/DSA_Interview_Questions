//& Write a function to merge two sorted binary search tree.

//& Ex:- 7

//~    7
//~   / \
//~  5   9

//~    4
//~   / \
//~  3   12

//& OP:- [3,4,5,6,7,8,12]
//& Given Inorder traversal of both tree, return inorder traversal of resultant tree.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

vector<int> merge(vector<int> v1, vector<int> v2)
{
    vector<int> res;
    int n1 = v1.size(), n2 = v2.size();
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        while (i < n1 && j < n2 && v1[i] <= v2[j])
        {
            res.push_back(v1[i++]);
        }
        while (i < n1 && j < n2 && v1[i] > v2[j])
        {
            res.push_back(v2[j++]);
        }
    }
    while (i < n1)
    {
        res.push_back(v1[i++]);
    }
    while (j < n2)
    {
        res.push_back(v2[j++]);
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<int> v1 = {5, 7, 9};
    vector<int> v2 = {3, 4, 12};
    vector<int> v = merge(v1, v2);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
