//& Write a program to remove duplicates from a sorted array in place.

//^ Solution

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void removeDups(vector<int> &v)
{
    int index = 0;
    for (int i = 1; i < v.size(); i++)
    {
        //* Index will always be at index of first number of given same number
        //* So using (i) we'll find next different number than index and replace it with next of index
        //* now that index will be our index of first number of next given same number
        if (v[i] != v[index])
        {
            index++;
            v[index] = v[i];
        }
    }
    int ind = v.size();
    while (ind-- != index + 1)
    {
        v.pop_back();
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> v = {1, 2, 2, 2, 3, 3, 4, 5, 6, 6};
    removeDups(v);
    for (auto i : v)
    {
        cout << i << endl;
    }

    return 0;
}