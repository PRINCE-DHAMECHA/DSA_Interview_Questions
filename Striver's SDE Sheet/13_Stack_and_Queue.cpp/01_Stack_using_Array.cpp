//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    bool pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void print();
};

bool Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        cout << "Stack Overflow" << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " Pushed into stack" << endl;
        return true;
    }
}

bool Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack is Empty" << endl;
        return false;
    }
    else
    {
        top--;
        return true;
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty" << endl;
        return false;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::isFull()
{
    return (top == MAX - 1);
}

void Stack::print()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
        return;
    }
    else
    {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is : " << s.peek() << endl;
    s.pop();
    cout << "Top element is : " << s.peek() << endl;
    s.print();
    return 0;
}

//~ Advantages of array implementation:
//* Easy to implement.
//* Memory is saved as pointers are not involved.

//~ Disadvantages of array implementation:
//* It is not dynamic i.e., it doesn’t grow and shrink depending on needs at runtime. [But in case of dynamic sized arrays like vector in C++, list in Python, ArrayList in Java, stacks can grow and shrink with array implementation as well].
//* The total size of the stack must be defined beforehand.