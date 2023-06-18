//& Given start and end time of meetings return maximum number of meeting you can accommodate in single room where you can host one meeting at a time.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach
//* SOrt by end time and greedily start assigning meetings

int maxMeetings(int start[], int end[], int n)
{
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    int endT = v[0][0];
    int count = 0;
    count++;
    for (int i = 1; i < v.size(); i++)
    {
        //* If previous meet end before starting of new one
        if (endT < v[i][1])
        {
            count++;
            endT = v[i][0];
        }
    }
    return count;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}