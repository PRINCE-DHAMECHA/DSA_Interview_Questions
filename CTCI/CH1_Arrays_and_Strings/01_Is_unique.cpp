//& Question:  Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

//^ Solution:

//~ Approach-1 :- Hashmap

//~ Approach-2 :- Take boolean vector where v[i] stores 0 if i exists and 0 otherwise
//! Not very space efficient

//~ Approach-3 :- Assume only lowercase letters, Using bit vector

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

bool isUnique(string s)
{
    int checker = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int val = s[i] - 'a';
        //* We're checking if previously we've set (val)th bit to 1 or not
        if ((checker & (1 << val)) > 0)
        {
            return false;
        }
        //* We're setting (val)th bit from end to 1
        checker |= (1 << val);
    }
    return true;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << isUnique("dfjdhfgsd") << endl;
    cout << isUnique("qwerty") << endl;
    return 0;
}

//! If we don't have additional DS

//~ Approach-4 :- Sort given string O(nlogn)

//~ Approach-5 :- Compare each character with all other O(n^2)