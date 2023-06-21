//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 - Making enQueue operation costly

class Queue
{
    stack<int> s1, s2;

public:
    void enQueue(int x);
    int deQueue();
};

void Queue::enQueue(int x) //* O(n)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int Queue::deQueue() //* O(1)
{
    if (s1.empty())
    {
        cout << "Queue is Empty" << endl;
        return INT_MIN;
    }
    int x = s1.top();
    s1.pop();
    return x;
}

//~ Approach:2 - Making deQueue operation costly

class Queue2
{
    stack<int> s1, s2;

public:
    void enQueue(int x);
    int deQueue();
};

void Queue2::enQueue(int x) //* O(1)
{
    s1.push(x);
}

//* the amortized complexity of the dequeue operation becomes Theta(1)
//* Here we make s2 suc that popping it will give first element and if s2 is empty then we fill it using s1
int Queue2::deQueue()
{
    if (s1.empty() && s2.empty())
    {
        cout << "Queue is Empty" << endl;
        return INT_MIN;
    }
    //* If empty then use s1 to fill it
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    //* If not empty then it will give first element
    int x = s2.top();
    s2.pop();
    return x;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    // Queue q;
    // q.enQueue(1);
    // q.enQueue(2);
    // q.enQueue(3);
    // cout << q.deQueue() << '\n';
    // q.enQueue(4);
    // cout << q.deQueue() << '\n';
    // cout << q.deQueue() << '\n';
    // cout << q.deQueue() << '\n';
    Queue2 q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    cout << q.deQueue() << '\n';
    q.enQueue(4);
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    return 0;
}