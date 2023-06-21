//& Implement medianFinder class.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* Here we need to continuously add element and find their median any time.
//* We take two priority queue, One with greater and other with smaller number priority.
//* Now we'll have two scenarios [k,k+1] --> [k+1,k+1] and [k,k] --> [k,k+1]
//* But we can't just add num to bigger in second case we need to pass it through smaller first and take biggest from there so we get right median when we pop from bigger and vice versa for first case

class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> maxi;
    priority_queue<int> mini;
    bool even = true;

    void addNum(int num)
    {
        if (even)
        {
            //* We insert first in mini and then extract max from it to append in maxi
            mini.push(num);
            maxi.push(mini.top());
            mini.pop();
        }
        else
        {
            //* We insert first in maxi and then extract min from it to append in mini
            maxi.push(num);
            mini.push(maxi.top());
            maxi.pop();
        }
        even = !even;
    }

    double findMedian()
    {
        if (even)
        {
            //* If even then we take middle two element
            return (mini.top() + maxi.top()) / 2.0;
        }
        else
        {
            //* Otherwise minimum of k+1 element from maxi
            return maxi.top();
        }
    }
};

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}