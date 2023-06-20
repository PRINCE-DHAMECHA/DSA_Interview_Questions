//& Part given string into substring such that all substring will be palindrome. Find all such partitions.
//^ Ex: aab :- [[a,a,b],[aa,b]]

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

bool isPal(string str)
{
    int start = 0, end = str.size() - 1;
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}
void findPalPart(string rem, vector<string> &strings, vector<vector<string>> &ans)
{
    if (rem == "")
    {
        ans.push_back(strings);
    }
    //* We take all possible substring of remaining string starting from 0 of any length
    //* When we find substring which is palindrome we recursively call for remaining string
    for (int i = 0; i < rem.size(); i++)
    {
        string temp = rem.substr(0, i + 1);
        if (isPal(temp))
        {
            strings.push_back(temp);
            findPalPart(rem.substr(i + 1), strings, ans);
            strings.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> strings;
    vector<vector<string>> ans;
    //* We start with full string
    findPalPart(s, strings, ans);
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}