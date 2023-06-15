//& Question:  Rotate given matrix to 90 degree.

//^ Solution:
//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* Rotate layer wise.

void rotateMat(vector<vector<int>> &mat)
{
    if (mat.size() != 0 || mat.size() == mat[0].size())
    {
        int n = mat.size();
        for (int layer = 0; layer < n / 2; layer++)
        {
            int first = layer, last = n - layer - 1;
            for (int i = first; i < last; i++)
            {
                //* offset means how deep is first element
                int offset = i - first;
                //* Store leftmost top
                int top = mat[first][i];
                //* change leftmost top with leftmost bottom
                mat[first][i] = mat[last - offset][first];
                //* same as above for other
                mat[last - offset][first] = mat[last][last - offset];
                mat[last][last - offset] = mat[i][last];
                mat[i][last] = top;
            }
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotateMat(v);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    rotateMat(v);
    rotateMat(v);
    rotateMat(v);
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
