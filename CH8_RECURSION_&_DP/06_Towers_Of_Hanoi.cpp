//? Idea :
//* if n=1=> Simply push to destination
//* if n=2=> Take top and push to buffer and then take bottom one and push to dest and then take from buffer and push to destination
//* if n=3=> Can we use n=2 to perform n=3? Yes, take above 2 disks to buffer as destination and then put bottom one at destination and push buffer's 2 disks to destination using source as buffer
//* if n=4=> Do above method, now instead 2 disks we have 3 disks
//* if n=k=> Take above k-1 disks and move to buffer using destination as buffer and move last disk to destination and now move k-1 disks from buffer to destination using source as buffer
//& BINGO!!

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;

class Tower
{
    stack<int> disks;

public:
    void add(int d)
    {
        //* Can't place disk d if it's below disk is smaller
        if (!disks.empty() && disks.top() <= d)
        {
            cout << "Error Placing Disk: " << d << endl;
            exit(0);
        }
        else
        {
            disks.push(d);
        }
    }
    void moveTopTo(Tower *t)
    {
        int top = disks.top();
        disks.pop();
        t->add(top);
    }
    void moveDisks(int n, Tower *dest, Tower *buffer)
    {
        if (n > 0)
        {
            //* buffer as dest and dest as buffer
            moveDisks(n - 1, buffer, dest);
            moveTopTo(dest);
            //* dest as dest and source as buffer
            buffer->moveDisks(n - 1, dest, this);
        }
    }
    void print(bool flag)
    {
        if (disks.empty())
        {
            if (flag)
            {
                cout << "Tower is empty!!";
            }
            return;
        }
        int x = disks.top();
        disks.pop();
        this->print(false);
        cout << x << " ";
        disks.push(x);
    }
};

#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Tower tower[3];
    int n = 10;
    for (int i = 10; i > 0; i--)
    {
        tower[0].add(i);
    }
    cout << "Before:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Tower: " << i << endl;
        tower[i].print(true);
        cout << endl;
    }
    cout << "After:" << endl;
    tower[0].moveDisks(n, &tower[2], &tower[1]);
    for (int i = 0; i < 3; i++)
    {
        cout << "Tower: " << i << endl;
        tower[i].print(true);
        cout << endl;
    }
    return 0;
}