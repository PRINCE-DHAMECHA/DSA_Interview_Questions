//& Right rotate given list by k nodes

//^ 1->2->3->4->5->NULL , k=2
//^ 4->5->1->2->3->NULL

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

//~ Approach:1 :-
//* Take above example, We went straight to kth node from last and point it to NULL and remaining list's last element will be pointed to previous head and new head will be start of remaining list

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
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    int len = lenList(head);
    //! Be careful as k can be greater than length of the list and for this case we take modulo because we know that after len rotation list will be the same
    k = k % len;
    if (k == 0)
    {
        return head;
    }
    for (int i = 0; i < k; i++)
    {
        if (fast != NULL)
        {
            fast = fast->next;
        }
        else
        {
            return head;
        }
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *temp = slow->next;
    ListNode *temp2 = slow->next;
    slow->next = NULL;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->next = head;
    }
    return temp2;
}

//~ Approach:2 :-
//* We remove last node and append it to first for k%len times

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
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k % lenList(head); i++)
    {
        ListNode *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        ListNode *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}