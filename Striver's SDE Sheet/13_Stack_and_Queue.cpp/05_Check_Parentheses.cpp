//& Check if given parentheses is valid or not.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We'll use stack :)

bool isValid(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '{' || i == '[' || i == '(')
        {
            st.push(i);
        }
        else
        {
            if (i == '}')
            {
                if (st.size() == 0)
                {
                    return false;
                }
                char x = st.top();
                st.pop();
                if (x != '{')
                {
                    return false;
                }
            }
            if (i == ')')
            {
                if (st.size() == 0)
                {
                    return false;
                }
                char x = st.top();
                st.pop();
                if (x != '(')
                {
                    return false;
                }
            }
            if (i == ']')
            {
                if (st.size() == 0)
                {
                    return false;
                }
                char x = st.top();
                st.pop();
                if (x != '[')
                {
                    return false;
                }
            }
        }
    }
    return st.size() == 0;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}