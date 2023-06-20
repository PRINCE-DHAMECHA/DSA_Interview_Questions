//& Given string without space and list of words. Find all possible sentences by inserting spaces in given string by which all the words in string must belongs to given list of words.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Backtracking

void wordBreakHelper(string &s, vector<string> proc, vector<string> &dictionary, int ind, vector<string> &ans)
{
    if (ind == s.size())
    {
        string answer = "";
        for (auto i : proc)
        {
            answer += i;
            answer += " ";
        }
        ans.push_back(answer);
        return;
    }
    //* We try all possible places to insert space
    for (int i = ind; i < s.size(); i++)
    {
        string temp = s.substr(ind, i - ind + 1);
        if (find(dictionary.begin(), dictionary.end(), temp) != dictionary.end())
        {
            proc.push_back(temp);
            wordBreakHelper(s, proc, dictionary, i + 1, ans);
            //* Backtrack
            proc.pop_back();
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}