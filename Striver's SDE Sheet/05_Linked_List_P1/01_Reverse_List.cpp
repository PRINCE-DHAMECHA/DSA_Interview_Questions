//& Reverse Given List

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
//* We recursively go to last node with remembering it's prev and then we point curr to prev and prev to NULL (Null because at last first node will point to NULL when it became last)

ListNode *reverseList(ListNode *prev, ListNode *curr)
{
    if (curr->next == NULL)
    {
        curr->next = prev;
        prev->next = NULL;
        return curr;
    }
    ListNode *head = reverseList(curr, curr->next);
    curr->next = prev;
    prev->next = NULL;
    return head;
}
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    head = reverseList(head, head->next);
    return head;
}
ListNode *reverseList(ListNode *prev, ListNode *curr)
{
    if (curr->next == NULL)
    {
        curr->next = prev;
        prev->next = NULL;
        return curr;
    }
    ListNode *head = reverseList(curr, curr->next);
    curr->next = prev;
    prev->next = NULL;
    return head;
}
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    head = reverseList(head, head->next);
    return head;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}