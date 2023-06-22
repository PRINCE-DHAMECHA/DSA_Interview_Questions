//& Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/

int largestRectangleArea(vector<int> &heights)
{
    int len = heights.size();
    stack<int> st;
    int maxArea = 0;
    int i = 0;
    while (i <= len)
    {
        //* If given height is less than current top then we reach the limit as smallest current top height so i will be right end and next to top will be left end
        while (st.size() && (i == len || heights[st.top()] > heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        //* When encounter smaller element push our number
        st.push(i);
        i++;
    }
    return maxArea;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}