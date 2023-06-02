//& Question: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

vector<long> mem(100, -1);

long count_steps(int n)
{
    //* We need to take care of mem when n<0, because n<0 will not be valid index
    if (mem[n] != -1 && n >= 0)
    {
        return mem[n];
    }
    if (n < 0)
    {
        return 0;
    }
    //* We successfully reached last steps so it's a valid sequence of steps
    if (n == 0)
    {
        return mem[n] = 1;
    }
    //* We take all possible next steps which is 1,2 and 3.
    mem[n] = count_steps(n - 1) + count_steps(n - 2) + count_steps(n - 3);
    return mem[n];
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    //! Overflow at 53, so be careful and if needed talk about it with interviewer
    int n = 52;
    cout << count_steps(n) << endl;
    return 0;
}