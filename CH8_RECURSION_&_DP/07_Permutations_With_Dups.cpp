//& Question: Write a method to compute all permutations of a string that contains unique characters.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//^ Approach-1
//* if we have "bca" then all permutation of a,b,c,d with b,c and a in "bca" order will be putting d in all possible positions of "bca"
//* If we have all permutations of (a,b,c) then we can repeat this for all of its permutations to create permutations of (a,b,c,d)
//* Approach just like used for creating subsets
vector<string> allPermutations(string s)
{
    vector<string> allPerms;
    if (s.size() == 1)
    {
        allPerms.push_back(s);
        return allPerms;
    }
    string rem = s.substr(1);
    vector<string> perms = allPermutations(rem);
    for (auto i : perms)
    {
        for (int j = 0; j <= i.size(); j++)
        {
            string s1 = i.substr(0, j);
            string s2 = i.substr(j);
            string final = s1 + s[0] + s2;
            allPerms.push_back(final);
        }
    }
    return allPerms;
}

//^ Approach-2
//* if we have all permutations of n-1 size string then prepending remaining character of respective string will give all permutations of n
//* p(a1,a2,a3,a4)= {a1+p(a2,a3,a4)+a2+p(a1,a3,a4)+a3+p(a1,a2,a4)+a4+p(a1,a2,a3)}
vector<string> allPermutations2(string s)
{
    vector<string> perms;
    if (s.size() == 0)
    {
        perms.push_back("");
        return perms;
    }
    for (int i = 0; i < s.size(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        vector<string> partPerms = allPermutations2(left + right);
        for (auto j : partPerms)
        {
            perms.push_back(s[i] + j);
        }
    }
    return perms;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    vector<string> v = allPermutations2("abcd");
    for (auto i : v)
    {
        cout << i << endl;
    }
    cout << v.size() << endl;
    return 0;
}