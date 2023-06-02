//& Question: Implement an algorithm to print all valid combinations of n pairs of parentheses.

//^ Solution:

//~ Approach1:
//* build n=3 with n=2:
//* (()) -> (()()) After first left
//* (()) -> ((())) After second left
//* (()) -> ()(()) beginning
//* ()() -> (())() After first left
//* ()() -> ()(()) After second left
//* ()() -> ()()() beginning
//! Problem? Yes, Repetitions.
//* Use sets
//* Problem? Yes, Not Efficient.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

set<string> makeAllParens(int n)
{
    set<string> s;
    if (n == 1)
    {
        s.insert("()");
        return s;
    }
    set<string> parens = makeAllParens(n - 1);
    for (auto i : parens)
    {
        for (int j = 0; j < i.size(); j++)
        {
            if (i[j] == '(')
            {
                string s1 = i.substr(0, j + 1);
                string s2 = i.substr(j + 1);
                s.insert(s1 + "()" + s2);
            }
        }
        s.insert("()" + i);
    }
    return s;
}

//~ Approach2:
//* Build string from scratch
//* When we can add left? -> When there's left remaining we can always add it
//* When we can add right> -> When n(Right)<n(Left)
//* So just keep track of numbers

void parensHelper(vector<string> &allParens, int left, int right, string s = "")
{
    if (left < 0 || right < left)
    {
        return;
    }
    if (left == 0 && right == 0)
    {
        allParens.push_back(s);
        return;
    }
    if (left > 0)
    {
        s.push_back('(');
        parensHelper(allParens, left - 1, right, s);
        s.pop_back();
    }
    if (right > left)
    {
        s.push_back(')');
        parensHelper(allParens, left, right - 1, s);
        s.pop_back();
    }
    return;
}

vector<string> makeAllParens2(int n)
{
    vector<string> allParens;
    parensHelper(allParens, n, n);
    return allParens;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    set<string> allParens = makeAllParens(5);
    for (auto i : allParens)
    {
        cout << i << endl;
    }
    cout << allParens.size() << endl;
    vector<string> allParens2 = makeAllParens2(5);
    for (auto i : allParens2)
    {
        cout << i << endl;
    }
    cout << allParens2.size() << endl;
    return 0;
}