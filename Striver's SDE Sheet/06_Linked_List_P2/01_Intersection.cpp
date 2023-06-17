//& Given head of two LL, find whether given linked list intersects or not. If yes then return intersecting node.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//~ Approach
//* We first find bigger onr and move it's head for len(big)-len(small) times and then move both head together and check if the two matches somewhere before one getting NULL.

//* Function for finding length
int lenList(ListNode *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int len1 = lenList(headA);
    int len2 = lenList(headB);
    //* Deciding who's bigger and who's smaller one
    ListNode *big = len1 >= len2 ? headA : headB;
    ListNode *small = len1 >= len2 ? headB : headA;
    int diff = abs(len1 - len2);
    //* Moving head of bigger one
    while (diff--)
    {
        if (big == NULL)
        {
            return NULL;
        }
        else
        {
            big = big->next;
        }
    }
    //* Now moving both together
    while (big != NULL && small != NULL && big != small)
    {
        big = big->next;
        small = small->next;
    }
    //* Checking if it's equal condition which breaks the loop
    if (big == small)
    {
        return big;
    }
    return NULL;
}

//~ Approach:2
//* We move both list together and after hitting NULL we exchange heads of both so that they can reach to intersection at the same time

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    ListNode *a = headA;
    ListNode *b = headB;
    //* Whenever smaller hits NULL we set it to head of bigger one and vice versa
    //* So after smaller starting points to bigger now smaller lags behind bigger and bigger will then ahead of smaller by difference so both will be at same distance from intersection
    while (a != b)
    {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}