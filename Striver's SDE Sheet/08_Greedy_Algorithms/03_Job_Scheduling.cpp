//& Schedule given jobs which contains id, Deadline, and profit to maximize profit.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

//~ Approach:
//* We first make slots to accommodate maximum deadlines
//* Then we sort jobs in decreasing manner of profit
//* Starts from beginning and check if we can assign this job in any slots or not

vector<int> JobScheduling(Job arr[], int n)
{

    sort(arr, arr + n, [](Job a, Job b)
         { return (a.profit > b.profit); });
    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].dead);
    }

    int slot[maxi + 1];

    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return {countJobs, jobProfit};
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}