//& Question: Sort an array of strings so that all the anagrams are next to each other.

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
//* What is anagram?
//* two strings which contains same sets of character and their occurrences
//* Ex:- triangle and integral is anagram

//* Now how can we identify and group them?
//* sort all string and now anagrams will be represented by same string.
//* Ex:- aegilnrt
//* Now sort this strings and we have our answer

void groupAnagrams(vector<string> &v)
{
    for (auto &i : v)
    {
        sort(i.begin(), i.end());
    }
    sort(v.begin(), v.end());
}

//~ Approach:2 :-
//* We didn't instructed to group in sorted method so why we make our algorithm inefficient?
//* Just use map

void groupAnagrams2(vector<string> &v)
{
    map<string, int> mp;
    for (auto &i : v)
    {
        sort(i.begin(), i.end());
        mp[i]++;
    }
    v.clear();
    for (auto i : mp)
    {
        int count = i.second;
        while (count--)
        {
            v.push_back(i.first);
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<string> v = {"triangle", "integral", "are", "we", "rea", "ew", "hii"};
    // groupAnagrams(v);
    groupAnagrams2(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}