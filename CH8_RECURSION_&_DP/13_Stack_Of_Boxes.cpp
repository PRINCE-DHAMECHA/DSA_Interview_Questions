//& Question: You have stack of n boxes, with dimensions w, h and d. The boxes cannot be rotated and can only be stacked on top of one another if all dimensions are strictly less than below. Make stack of boxes such that sum of their height will be maximum.

//^ Solution:

//~ Approach:
//* Backtrack

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

vector<int> MEM(100, -1);

class Box
{
public:
    int width, height, depth;
    Box(int width, int height, int depth)
    {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    bool operator<(const Box &other) const
    {
        return height > other.height;
    }
    bool canBeUnder(Box b);
    bool canBeAbove(Box b);
};

bool Box::canBeUnder(Box b)
{
    if (width > b.width && height > b.height && depth > b.depth)
    {
        return true;
    }
    return false;
}

bool Box::canBeAbove(Box b)
{
    if (&b == NULL)
    {
        return true;
    }
    if (width < b.width && height < b.height && depth < b.depth)
    {
        return true;
    }
    return false;
}

int createStack(vector<Box> boxes, int bottomIndex)
{
    if (MEM[bottomIndex] != -1)
    {
        return MEM[bottomIndex];
    }
    Box bottom = boxes[bottomIndex];
    int maxHeight = 0;
    //* try every box on top of bottom one and recursively try every one on top of it
    for (int i = bottomIndex + 1; i < boxes.size(); i++)
    {
        //! First check whether we can put this box on bottom one or not
        if (boxes[i].canBeAbove(bottom))
        {
            int height = createStack(boxes, i);
            maxHeight = max(height, maxHeight);
        }
    }
    //* Add height of bottom box
    maxHeight += bottom.height;
    return MEM[bottomIndex] = maxHeight;
}
int createStack(vector<Box> boxes)
{
    //* Sorting according to height so we don't need to worry about smaller ones
    sort(boxes.begin(), boxes.end());
    int maxHeight = 0;
    for (int i = 0; i < boxes.size(); i++)
    {
        int height = createStack(boxes, i);
        maxHeight = max(maxHeight, height);
    }
    return maxHeight;
}

//~ Approach2: Dynamic Programming

//* Stack will be just choice of yes or no for selecting every box
//* Will try every possibility after selecting particular box and take maximum answer
int createStackDP(vector<Box> &boxes, Box *bottom, int offset, vector<int> &stackMap)
{
    if (offset >= boxes.size())
    {
        return 0;
    }
    Box newBottom = boxes[offset];
    int heightWithBottom = 0, heightWithoutBottom = 0;
    if (bottom == NULL || newBottom.canBeAbove(*bottom))
    {
        //* Memoization
        if (stackMap[offset] == 0)
        {
            stackMap[offset] = createStackDP(boxes, &newBottom, offset + 1, stackMap);
            stackMap[offset] += newBottom.height;
        }
        heightWithBottom = stackMap[offset];
    }
    heightWithoutBottom = createStackDP(boxes, bottom, offset + 1, stackMap);
    return max(heightWithBottom, heightWithoutBottom);
}

//* Same as discussed in previous Approach
int createStackDP(vector<Box> boxes)
{
    sort(boxes.begin(), boxes.end());
    vector<int> stackMap(boxes.size(), 0);
    return createStackDP(boxes, NULL, 0, stackMap);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<Box> boxes;
    boxes.push_back(Box(5, 3, 3));
    boxes.push_back(Box(6, 5, 4));
    boxes.push_back(Box(8, 6, 2));
    boxes.push_back(Box(9, 7, 3));
    boxes.push_back(Box(7, 8, 5));
    int height1 = createStack(boxes);
    int height2 = createStackDP(boxes);
    //* Should be equal
    cout << height1 << " " << height2 << endl;
    return 0;
}