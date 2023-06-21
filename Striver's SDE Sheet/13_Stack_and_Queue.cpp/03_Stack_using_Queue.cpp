//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class Stack
{
    queue<int> q;

public:
    void push(int x);
    void pop();
    int top();
    bool empty();
};

void Stack::push(int val)
{
    int s = q.size();
    q.push(val);
    for (int i = 0; i < s; ++i)
    {
        //* Remove other element and push it back so that val will be in front
        q.push(q.front());
        q.pop();
    }
}

void Stack::pop()
{
    if (q.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        q.pop();
    }
}

int Stack::top()
{
    return q.empty() ? INT_MIN : q.front();
}

bool Stack::empty()
{
    return q.empty();
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;
    s.pop();
    s.push(30);
    s.pop();
    cout << s.top() << endl;
    return 0;
}