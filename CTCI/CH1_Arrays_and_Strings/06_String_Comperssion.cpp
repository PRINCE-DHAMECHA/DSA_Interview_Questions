//& Question:  Compress given string.
//& Ex: aabccc :- a2b1c3, abc :- abc

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
//* count occurrences and append count

string compressStr(string str)
{
    string comp = "";
    int cons = 0;
    for (int i = 0; i < str.size(); i++)
    {
        cons++;
        if (i + 1 >= str.size() || str[i] != str[i + 1])
        {
            comp += str[i];
            comp += (cons + '0');
            cons = 0;
        }
    }
    return comp.size() > str.size() ? str : comp;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    cout << compressStr("abbbcccccss") << endl;
    cout << compressStr("abcde") << endl;
    return 0;
}
