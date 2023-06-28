//& There is at most one celebrity in party who knows nobody but everyone knows him. There's function implemented knows(A,B) which returns true if A knows B and false otherwise. Find celebrity and if there's no celebrity then return -1.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use stack and push local celebrity from top two person and pop other and then cross check it to verify if our celebrity is actual celebrity or not :)

#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

bool knows(int A, int B)
{
    //* Already implemented
    return true;
}

int findCelebrity(int n)
{
    stack<int> st;
    //* Push all
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    //* Check until there's only one person left
    while (st.size() >= 2)
    {
        //* Pop top two
        int x = st.top();
        st.pop();
        int y = st.top();
        st.pop();
        //* Push whoever didn't know other
        //* If both knows then also we push only one because there's only at most one celebrity
        if (knows(x, y))
        {
            st.push(y);
        }
        else
        {
            st.push(x);
        }
    }
    //* Pop remaining person which can potentially our celebrity
    int cel = st.top();
    for (int i = 0; i < n; i++)
    {
        //* If he knows ith person or ith person didn't know him then he can't be our celebrity
        if (cel != i && (knows(cel, i) || !(knows(i, cel))))
        {
            return -1;
        }
    }
    return cel;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}