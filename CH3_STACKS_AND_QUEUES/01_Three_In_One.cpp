//& Question:  Make 3 stacks using only one array

//^ Solution:

//~ Approach-1
//* We can divide array in 3 parts and each parts will be used as one stack
//* Inefficient approach.

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
    int *arr;
    int *top;
    int size;

public:
    Stack(int n)
    {
        size = n;
        arr = new int[n];
        top = new int[3];
        //* First stack from 0  to (n / 3) - 1
        top[0] = -1;
        top[1] = (n / 3) - 1;
        top[2] = ((2 * n) / 3) - 1;
    }
    void push(int x, int sn);
    int pop(int sn);
};

void Stack::push(int x, int sn)
{
    if (top[sn] >= ((sn + 1) * size / 3) - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        top[sn]++;
        arr[top[sn]] = x;
    }
}

int Stack::pop(int sn)
{
    if (top[sn] <= (sn * size / 3) - 1)
    {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }
    else
    {
        int x = arr[top[sn]];
        top[sn]--;
        return x;
    }
}

class KStacks
{
    //* Array of size n to store actual content to be stored in stacks
    int *arr;
    //* Array of size k to store indexes of top elements of stacks
    int *top;
    //* Array of size n to store next entry in all stacks and free list
    int *next;
    int n, k;
    //* To store beginning index of free list
    int free;

public:
    //* constructor to create k stacks in an array of size n
    KStacks(int k, int n);

    //* A utility function to check if there is space available
    bool isFull() { return (free == -1); }

    //* To push an item in stack number 'sn' where sn is from 0 to k-1
    void push(int item, int sn);

    //* To pop an from stack number 'sn' where sn is from 0 to k-1
    int pop(int sn);

    //* To check whether stack number 'sn' is empty or not
    bool isEmpty(int sn) { return (top[sn] == -1); }
};

KStacks::KStacks(int k1, int n1)
{
    k = k1, n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    for (int i = 0; i < k; i++)
    {
        top[i] = -1;
    }
    //* Initialize all spaces as free
    free = 0;
    for (int i = 0; i < n - 1; i++)
    {
        next[i] = i + 1;
    }
    //! -1 is used to indicate end of free list
    next[n - 1] = -1;
}

void KStacks::push(int x, int sn)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    int i = free;
    free = next[i];
    //* We're just remembering previous top of current stack using next, so every time we update top we store that first in corresponding next
    next[i] = top[sn];
    //* Current position will be top of stack sn
    top[sn] = i;
    arr[i] = x;
}

int KStacks::pop(int sn)
{
    if (isEmpty(sn))
    {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Stack s(10);
    s.push(1, 0);
    s.push(2, 0);
    s.push(3, 0);
    cout << s.pop(0) << endl;
    s.push(4, 1);
    s.push(5, 1);
    cout << s.pop(1) << endl;
    cout << s.pop(1) << endl;
    s.push(6, 1);
    cout << s.pop(1) << endl;
    s.push(7, 2);
    s.push(8, 2);
    s.push(9, 2);
    s.push(10, 2);
    cout << s.pop(2) << endl;
    s.push(15, 0);
    s.push(25, 2);
    cout << s.pop(0) << endl;
    cout << s.pop(2) << endl;

    int k = 3, n = 10;
    KStacks ks(k, n);

    ks.push(15, 2);
    ks.push(45, 2);

    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    return 0;
}

//~ Approach-2
//* We try to  generalize given problem where we implement K-stacks in given array
