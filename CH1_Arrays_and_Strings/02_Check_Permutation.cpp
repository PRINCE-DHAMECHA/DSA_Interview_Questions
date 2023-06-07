//& Question:  Given two string, write a method to decide if one is permutation of other.

//! Comparison is case sensitive and white space is significant i.e. "dog   " is not a permutation of "gdo"

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach-1 :-
//* We know permutation of one string is nothing but putting character of that particular string in different order
//* Sort given strings and compare O(nlogn) / O(1)

bool isPermutation(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

//~ Approach-2 :- O(n) / O(1)
//* Count characters of each string and compare
//! Be careful about character set // Here we assumed ASCII

bool isPermutation2(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    vector<int> chars(128, 0);
    for (auto i : s1)
    {
        chars[i]++;
    }
    for (auto i : s2)
    {
        chars[i]--;
        if (chars[i] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    cout << isPermutation("abcd", "bdca") << endl;
    cout << isPermutation("abcd", "bdsa") << endl;
    cout << isPermutation2("abcd", "bdca") << endl;
    cout << isPermutation2("abcd", "bdsa") << endl;

    return 0;
}
