//& Question:  There are three types of edits that can be performed on strigs: insert a character, remove a character, or replace a character. Given two string, write a function to check if they are one edit(or Zero edit) away.

//^ Solution:
//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach :-

//* What is insertion? -> Strings is identical except for one shift
//* What is removal? -> It's insertion but order of string is reverse
//* What is replacement? -> length is same but only one character is different

//^ Implementation-1 :-

bool oneEditReplace(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    bool foundDiff = false;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            //* It's second different character
            if (foundDiff)
            {
                return false;
            }
            //* It's first different character
            foundDiff = true;
        }
    }
    return true;
}

bool oneEditInsert(string s1, string s2)
{
    if (abs(s1.size() - s2.size()) > 1)
    {
        return false;
    }
    if (s1.size() > s2.size())
    {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    int ind1 = 0;
    int ind2 = 0;
    while (ind1 < s1.size() && ind2 < s2.size())
    {
        if (s1[ind1] != s2[ind2])
        {
            //* If second mismatch happen then we know that index will not be same
            if (ind1 != ind2)
            {
                return false;
            }
            //* We allow first mismatch and increase index of second string as we know s2>s1(size)
            ind2++;
        }
        else
        {
            ind1++;
            ind2++;
        }
    }
    return true;
}

bool oneEditAway1(string first, string second)
{
    return oneEditInsert(first, second) || oneEditReplace(first, second);
}

//^ Implementation-2 :-
//* We can combine replace and insert/remove in one function

bool oneEditAway2(string s1, string s2)
{
    if (abs(s1.size() - s2.size()) > 1)
    {
        return false;
    }
    if (s1.size() > s2.size())
    {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    int ind1 = 0, ind2 = 0;
    bool foundDiff = false;
    while (ind1 < s1.size() && ind2 < s2.size())
    {
        if (s1[ind1] != s2[ind2])
        {
            if (foundDiff)
            {
                return false;
            }
            foundDiff = true;
            if (s1.size() == s2.size())
            {
                ind1++;
            }
        }
        else
        {
            ind1++;
        }
        //* Move ind2 always
        ind2++;
    }
    return true;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << oneEditAway1("pale", "ple") << endl;
    cout << oneEditAway1("pales", "pale") << endl;
    cout << oneEditAway1("bale", "pale") << endl;
    cout << oneEditAway1("bae", "pale") << endl;
    cout << oneEditAway2("pale", "ple") << endl;
    cout << oneEditAway2("pales", "pale") << endl;
    cout << oneEditAway2("bale", "pale") << endl;
    cout << oneEditAway2("bae", "pale") << endl;
    return 0;
}
