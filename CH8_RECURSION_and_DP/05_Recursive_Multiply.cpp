//& Question: Write a method to do multiplication without * operator. You can use +, - and bit operations but make sure to minimize count of this operations.p

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

vector<int> MEM(10000, -1);

//* Think 8*5 as 2 times 4*5, And 9*5 as 4*5 + 5*5
int multiplyHelper(int smaller, int bigger)
{
    if (MEM[smaller] != -1)
    {
        return MEM[smaller];
    }
    if (smaller == 0)
    {
        return 0;
    }
    else if (smaller == 1)
    {
        return bigger;
    }
    int half = smaller >> 1;
    int side1 = multiplyHelper(half, bigger);
    int side2 = side1;
    if (smaller % 2)
    {
        side2 = multiplyHelper(smaller - half, bigger);
    }
    return MEM[smaller] = side1 + side2;
}

//* Think 8*5 as 2 times 4*5 , And 9*5 as 4*5 + 4*5 + 5
int multiplyHelperNew(int smaller, int bigger)
{
    if (MEM[smaller] != -1)
    {
        return MEM[smaller];
    }
    if (smaller == 0)
    {
        return 0;
    }
    else if (smaller == 1)
    {
        return bigger;
    }
    int half = smaller >> 1;
    int side1 = multiplyHelperNew(half, bigger);
    int side2 = side1;
    if (smaller % 2)
    {
        side2 += bigger;
    }
    return MEM[smaller] = side1 + side2;
}

int multiply(int a, int b)
{
    int smaller = a < b ? a : b;
    int bigger = a < b ? b : a;
    //^ int ans = multiplyHelper(smaller, bigger);
    int ans = multiplyHelperNew(smaller, bigger);
    return ans;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    int a = 29, b = 8;
    int mul = multiply(a, b);
    cout << mul << endl;

    return 0;
}