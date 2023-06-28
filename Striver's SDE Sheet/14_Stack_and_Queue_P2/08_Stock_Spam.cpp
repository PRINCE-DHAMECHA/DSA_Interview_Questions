// //& Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day. The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

//^ For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
//^ Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
//^ Implement the StockSpanner class:

//& StockSpanner() Initializes the object of the class.
//& int next(int price) Returns the span of the stock's price given that today's price is price.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:1 :-
//* We use vector of pair to store price and it's span
//* We use this spam for future uses
//* We start counting span from end we skip span of each price because already know if given element is smaller then given price then it's span will be also valid for given price

class StockSpanner
{
public:
    vector<pair<int, int>> vp;
    StockSpanner()
    {
    }

    int next(int price)
    {
        if (vp.size() == 0)
        {
            vp.push_back({price, 1});
            return 1;
        }
        int i = vp.size() - 1;
        int count = 1;
        while (i >= 0)
        {
            if (vp[i].first <= price)
            {
                count += vp[i].second;
                i -= vp[i].second;
            }
            else
            {
                break;
            }
        }
        vp.push_back({price, count});
        return count;
    }
};

//~ Approach:2 :-
//* We use stack to remove unnecessary elements which already less than later price

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int mini = 1;
        //* We pop smaller one for current element because it'll not useful for later price also
        //* Only span count matters for those
        while (st.size() && st.top().first <= price)
        {
            auto top = st.top();
            st.pop();
            mini += top.second;
        }
        st.push({price, mini});
        return mini;
    }
};

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}