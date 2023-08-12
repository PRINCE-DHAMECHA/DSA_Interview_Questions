//& Reverse order of words in given string.
//! Handle leading and tailing spaces and also multiple spaces.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We recurse through last word and add that first and then we add remaining while popping

void reverseWordsHelper(string s, string &res, int index = 0)
{
    if (index >= s.size())
    {
        return;
    }
    //* Ignore multiple spaces
    if (s[index] == ' ')
    {
        reverseWordsHelper(s, res, index + 1);
        return;
    }
    //* Note first character index of given word
    int ind = index + 1;
    //* And find last
    while (ind < s.size() && s[ind] != ' ')
    {
        ind++;
    }
    //* Recursively go to last
    reverseWordsHelper(s, res, ind);
    res.push_back(' ');
    //* Add current one
    for (int i = index; i < ind; i++)
    {
        res.push_back(s[i]);
    }
}

string reverseWords(string s)
{
    string res = "";
    reverseWordsHelper(s, res, 0);
    //* To handle space of last word
    if (res.size() != 0 && res[0] == ' ')
    {
        return res.substr(1);
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}