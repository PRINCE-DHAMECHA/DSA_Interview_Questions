//& Find Starting of cycle in given list
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
//* https://github.com/PRINCE-DHAMECHA/DSA_Interview_Questions/blob/main/CTCI/CH2_Linked_Lists/08_Loop_Detect.cpp

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    ListNode *l1 = head->next;
    ListNode *l2 = head->next != NULL ? head->next->next : NULL;
    while (l2 != NULL && l2->next != NULL && l1 != l2)
    {
        l1 = l1->next;
        l2 = l2->next->next;
    }
    if (l1 != l2)
    {
        return NULL;
    }
    l1 = head;
    while (l1 != l2)
    {
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}