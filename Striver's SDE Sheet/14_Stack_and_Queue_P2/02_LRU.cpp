//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class LRUCache
{
public:
    //* Used as cache storage
    list<pair<int, int>> ll;
    //* Used for keeping track of cache elements
    //! Map will store iterator to key-value in cache
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int cacheSize;
    LRUCache(int capacity)
    {
        cacheSize = capacity;
    }
    //* If key exist then we push it to beginning
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            //* Exctract key an value
            auto temp = mp[key];
            auto key = temp->first;
            auto val = temp->second;
            //* Remove from in between
            ll.erase(mp[key]);
            //* Push front
            ll.push_front({key, val});
            //* Update map
            mp[key] = ll.begin();
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        //* If element are not there in cache
        if (mp.find(key) == mp.end())
        {
            //* If size exceed then remove last element
            if (ll.size() == cacheSize)
            {
                auto last = ll.back();
                ll.pop_back();
                mp.erase(last.first);
            }
        }
        //* Else remove from in between
        else
        {
            ll.erase(mp[key]);
        }
        //* For both case insert at beginning
        ll.push_front({key, value});
        mp[key] = ll.begin();
    }
};

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}