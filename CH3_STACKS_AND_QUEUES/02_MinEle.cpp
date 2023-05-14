//& Get min element of stack in O(1)

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//? Approach-1 :- Keep two stack, one for actual elements and other for pushing min element
//* Inefficient as we need O(n) Auxilary space

//? Approach-2 :- instead of pushing original element, if element less than min we'll push 2*ele -  min

//~ Push(x): Insert x at the top of the stack
//& If the stack is empty, insert x into the stack and make minEle equal to x.
//& If the stack is not empty, compare x with minEle. Two cases arise:
//& If x is greater than or equal to minEle, simply insert x.
//& If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x.

//~ Pop(): Removes an element from the top of the stack

//& Remove the element from the top. Let the removed element be y. Two cases arise:
//& If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
//& If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve the previous minimum from the current minimum and its value in the stack.

//? How does this works?
//* When the element to be inserted is less than minEle, we insert “2x – minEle”. The important thing to note is, that 2x – minEle will always be less than x i.e. new minEle
//* while popping out this element we will see that something unusual has happened as the popped element is less than the minEle. So we will be updating minEle.

class MyStack
{
    stack<int> s;
    int minEle;

public:
    int getMin();
    int peek();
    int pop();
    void push(int x);
};

int MyStack::getMin()
{
    if (s.empty())
    {
        cout << "Stack is Empty";
        exit(1);
    }
    else
    {
        return minEle;
    }
}

int MyStack::peek()
{
    if (s.empty())
    {
        cout << "Stack is Empty";
        exit(1);
    }
    else
    {
        int t = s.top();
        //* Only for minEle the top of the stack will be different as we push 2*ele-min otherwise top of the stack will be actual element
        return t < minEle ? minEle : t;
    }
}

void MyStack::push(int x)
{
    if (s.empty())
    {
        minEle = x;
        s.push(x);
        return;
    }
    else if (x < minEle)
    {
        s.push((2 * x) - minEle);
        minEle = x;
    }
    else
    {
        s.push(x);
    }
}

int MyStack::pop()
{
    if (s.empty())
    {
        cout << "Stack is Empty";
        exit(1);
    }
    int t = s.top();
    s.pop();
    if (t < minEle)
    {
        minEle = 2 * minEle - t;
        return minEle;
    }
    return t;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    MyStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    s.peek();
    return 0;
}