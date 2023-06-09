//& Sort(descending) given stack using only one extra stack, other than that you can't use any other data structure.

//^ Solution:

//* We make one stack as sorted, we pop from other and push it in right position in sorted stack
//* But how?
//* We pop s1(not sorted) and store that in temp and start popping from s2(sorted) and adding it to s1 while we didn't get right place in s2 for temp and then we do same process until s1 is not empty.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

void sort(stack<int> *s1)
{
    stack<int> s2;
    while (!s1->empty())
    {
        int temp = s1->top();
        s1->pop();
        while (!(s2.empty()) && (s2.top()) > temp)
        {
            s1->push(s2.top());
            s2.pop();
        }
        s2.push(temp);
    }
    while (!s2.empty())
    {
        s1->push(s2.top());
        s2.pop();
    }
}

void PrintStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    stack<int> s;
    s.push(4);
    s.push(2);
    s.push(31);
    s.push(4331);
    s.push(314);
    s.push(43);
    s.push(42);
    s.push(40);
    s.push(41);
    cout << "Before " << endl;
    PrintStack(s);
    sort(&s);
    cout << endl
         << "After: " << endl;
    PrintStack(s);
    return 0;
}