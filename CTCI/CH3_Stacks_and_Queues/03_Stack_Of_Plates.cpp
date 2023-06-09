//& Make SetOfStacks class which after filling one stack automatically creates new new stack and start pushing in it. Create method push and pop which behaves exactly like one stack. and create popAt(sn) method which pop from sn stack and shift next stacks element to it.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class SetOfStacks
{
    vector<stack<int>> stacks;
    int capacity;

public:
    SetOfStacks(int capacity)
    {
        this->capacity = capacity;
    }
    void push(int x);
    int pop();
    int popAt(int sn);
    void print();
};

void SetOfStacks::push(int x)
{
    if (stacks.size() == 0)
    {
        stack<int> s;
        stacks.push_back(s);
    }
    stack<int> *sn = &(stacks.back());
    if (sn->size() == capacity)
    {
        stack<int> s;
        stacks.push_back(s);
        sn = &(stacks.back());
    }
    sn->push(x);
    return;
}

int SetOfStacks::pop()
{
    if (stacks.size() == 0)
    {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }
    stack<int> *s = &(stacks.back());
    //* no need to check for empty stack as we'll remove empty stack each time we encounter one
    int x = s->top();
    s->pop();
    if (s->size() == 0)
    {
        stacks.pop_back();
    }
    return x;
}

//* sn will be 0 to k-1
int SetOfStacks::popAt(int sn)
{
    int size = stacks.size();
    if (sn == size - 1)
    {
        return pop();
    }
    if (sn >= size)
    {
        cout << "Enter valid stack index" << endl;
        return INT_MIN;
    }
    stack<int> *s = &(stacks[sn]);
    int x = s->top();
    s->pop();
    //* push bottom of next stack and do the same for next till second last
    while (sn != size - 1)
    {
        stack<int> *current = &(stacks[sn]);
        stack<int> *next = &(stacks[sn + 1]);
        stack<int> temp;
        if (next->size())
        {
            while (!(next->empty()))
            {
                temp.push(next->top());
                next->pop();
            }
            current->push(temp.top());
            temp.pop();
            while (!temp.empty())
            {
                next->push(temp.top());
                temp.pop();
            }
        }
        sn++;
    }
    //* If last stack is empty then remove from stacks
    if (stacks.back().size() == 0)
    {
        stacks.pop_back();
    }
    return x;
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

void SetOfStacks::print()
{
    for (auto &i : stacks)
    {
        PrintStack(i);
        cout << endl;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    SetOfStacks s(2);
    s.push(2);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(6);
    s.push(7);
    cout << s.pop() << endl;
    s.print();
    s.popAt(0);
    cout << "After Pop" << endl;
    s.print();
    s.popAt(1);
    cout << "After Pop" << endl;
    s.print();
    s.push(102);
    cout << "After Push" << endl;
    s.print();
    return 0;
}