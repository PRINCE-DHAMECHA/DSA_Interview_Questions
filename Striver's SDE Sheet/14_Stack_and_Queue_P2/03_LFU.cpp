//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We use three hashMaps
//* keyVal:- to store key and corresponding value and it's frequency
//* freqList:- Store list of all key-val with given frequency
//* pos:- To store position of given key

class LFUCache
{
public:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyVal;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key)
    {
        //* If given key is in cache
        if (keyVal.find(key) != keyVal.end())
        {
            //* We erase it from current frequency list
            freqList[keyVal[key].second].erase(pos[key]);
            //* Increase it's frequency
            keyVal[key].second++;
            //* Store in corresponding freqList
            freqList[keyVal[key].second].push_back(key);
            //* Update it's position
            pos[key] = --freqList[keyVal[key].second].end();
            //* If minFreq is empty means there's no element with given minimum frequency then we increase minFreq
            //* This means that we used current minFreq key and now the freq increased given that there's ony one key
            if (freqList[minFreq].empty())
            {
                minFreq++;
            }
            //* Return value of key
            return keyVal[key].first;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
        {
            return;
        }
        //* If key is in cache
        if (keyVal.find(key) != keyVal.end())
        {
            //* Then we update it's value and refer it using get function to update frequency
            keyVal[key].first = value;
            get(key);
            return;
        }
        //* If there's no more space
        if (keyVal.size() == capacity)
        {
            //* We delete least frequently used key from  all three map
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        //* Then we add given key value with
        keyVal[key] = {value, 1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}