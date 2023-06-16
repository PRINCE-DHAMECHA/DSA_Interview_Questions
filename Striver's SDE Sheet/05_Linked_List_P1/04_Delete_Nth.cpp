//& delete Nth element from last.

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

//~ Approach:1
//* We find nth node from last and delete it

ListNode *getNthEnd(ListNode *head, int index)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (len < index)
    {
        return NULL;
    }
    temp = head;
    for (int i = 1; i < len - index + 1; i++)
    {
        temp = temp->next;
    }
    return temp;
}
void removeNode(ListNode *head, ListNode *node)
{
    ListNode *prev = head;
    ListNode *curr = head->next;
    while (curr != node)
    {
        curr = curr->next;
        prev = prev->next;
    }
    prev->next = curr->next;
    return;
}
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *node = getNthEnd(head, n);
    if (node == head)
    {
        return head->next;
    }
    cout << node->val << endl;
    removeNode(head, node);
    return head;
}

//~ Approach:2
//* Make two pointer
//* One will be move n nodes first and then we start moving both together until fast became NULL

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *prev = new ListNode(0);
    ListNode *slow = prev, *fast = prev;
    slow->next = head;
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return prev->next;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}