//* Implement LRU(Least Recently Used) Cache

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class LRU
{
    list<int> dq;
    unordered_map<int, list<int>::iterator> mp;
    int cacheSize;

public:
    LRU(int);
    void refer(int);
    void display();
};

LRU::LRU(int cacheSize)
{
    this->cacheSize = cacheSize;
}

//* Refers given key in LRU Cache
void LRU::refer(int x)
{
    //* If key doesn't exist in LRU Cache
    if (mp.find(x) == mp.end())
    {
        //* If queue is full then we remove last element
        if (dq.size() == cacheSize)
        {
            int last = dq.back();
            dq.pop_back();
            mp.erase(last);
        }
    }
    //* If key exist in LRU then remove at that position and then we add at beginning
    else
    {
        dq.erase(mp[x]);
    }
    //* Now as characteristics of LRU, we add x at beginning for both case
    dq.push_front(x);
    mp[x] = dq.begin();
}

void LRU::display()
{
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    LRU ca(4);
    //* 1
    ca.refer(1);
    //* 2 1
    ca.refer(2);
    //* 3 2 1
    ca.refer(3);
    //* 1 3 2
    ca.refer(1);
    //* 4 1 3 2
    ca.refer(4);
    //* 5 4 1 3
    ca.refer(5);
    ca.display();
    return 0;
}
