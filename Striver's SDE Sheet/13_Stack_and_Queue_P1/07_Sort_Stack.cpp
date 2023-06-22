//& Sort given stack.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We'll use auxilary stack to sort given stack
//* We make one stack as sorted, we pop from other and push it in right position in sorted stack
//* But how?
//* We pop s1(not sorted) and store that in temp and start popping from s2(sorted) and adding it to s1 while we didn't get right place in s2 for temp and then we do same process until s1 is not empty.

//* In increasing order
void sortStack(stack<int> &s1)
{
    stack<int> s2;
    while (!s1.empty())
    {
        int temp = s1.top();
        s1.pop();
        while (!(s2.empty()) && (s2.top()) < temp)
        {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(temp);
    }
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

//* In decreasing order
void sortStack(stack<int> &s1)
{
    stack<int> s2;
    while (!s1.empty())
    {
        int temp = s1.top();
        s1.pop();
        while (!(s2.empty()) && (s2.top()) > temp)
        {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(temp);
    }
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}