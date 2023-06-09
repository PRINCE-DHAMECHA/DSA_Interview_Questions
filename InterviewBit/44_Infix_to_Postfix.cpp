//& Write a function to convert an infix expression to postfix expression

//~ Input: a+b*(c^d)
//~ Output: abcd^*+

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '/' || c == '*')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res;
    for (auto c : s)
    {
        //* If we encounter variable then directly add it
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            res += c;
        }
        //* push opening bracket
        else if (c == '(')
        {
            st.push('(');
        }
        //* pop stack until ( if you encounter )
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            //* Pop '(' Also
            st.pop();
        }
        else
        {
            //* pop all operator with prec higher than current one and push current one
            while (!st.empty() && prec(c) < prec(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    //* pop remaining stack
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    string inf = "a+b*(c^d)";
    cout << infixToPostfix(inf) << endl;
    return 0;
}