//& Make maximum profit according to fractional knapsack

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

struct Item
{
    int value;
    int weight;
};

//~ Approach
//* We sort according to profit/weight, try to take item with maximum profit and minimum weight
double fractionalKnapsack(int w, Item arr[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({arr[i].value, arr[i].weight});
    }
    sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2)
         { return (double)((double)p1.first / (double)p1.second) >= (double)((double)p2.first / (double)p2.second); });
    double profit = 0, i = 0;
    while (w > 0 && i < n)
    {
        if (w >= v[i].second)
        {
            w -= v[i].second;
            profit += v[i].first;
        }
        else
        {
            profit += (double)((double)v[i].first / (double)v[i].second) * (double)w;
            w = 0;
        }
        i++;
    }
    return profit;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}