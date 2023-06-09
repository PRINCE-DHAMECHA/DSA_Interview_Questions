//& Question:  Given URl with white space, replace all white spaces with "%20", You have enough space at the end to expand string
//! Don't create new string
//* EX:- "my url  " :- "my%20url"

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
//* We use two loops
//* In first one we count spaces and in second pass update from end

void URLify(string &s, int trueSize)
{
    int spaceCount = 0;
    for (int i = 0; i < trueSize; i++)
    {
        if (s[i] == ' ')
        {
            spaceCount++;
        }
    }
    int index = trueSize + (2 * spaceCount) - 1;
    for (int i = trueSize - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[index--] = '0';
            s[index--] = '2';
            s[index--] = '%';
        }
        else
        {
            s[index--] = s[i];
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    string s = "Mr John Smith    ";
    URLify(s, 13);
    cout << s << endl;
    return 0;
}
