//& Reverse nodes of list in given k intervals means first reverse first k node and then next k until remaining node is less than k.

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
//* We'll use previous code where we created reverse function for given left and right range, and we just provide range in it :)

ListNode *reverseBetween(ListNode *head, ListNode *prev, ListNode *curr, ListNode *prevP, ListNode *currP, int level, int left, int right)
{
    if (level == left)
    {
        return reverseBetween(head, curr, curr->next, prev, curr, level + 1, left, right);
    }
    if (level == right)
    {
        ListNode *temp = left == 1 ? curr : head;
        if (currP != NULL && curr != NULL)
        {
            currP->next = curr->next;
        }
        if (prevP != NULL)
        {
            prevP->next = curr;
        }
        if (currP != NULL && curr != NULL)
        {
            curr->next = prev;
        }
        return temp;
    }
    if (level > left && level < right)
    {
        if (curr != NULL)
        {
            ListNode *hd = reverseBetween(head, curr, curr->next, prevP, currP, level + 1, left, right);
            curr->next = prev;
            return hd;
        }
        return NULL;
    }
    if (curr != NULL && level < left)
    {
        return reverseBetween(head, curr, curr->next, prevP, currP, level + 1, left, right);
    }
    return NULL;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    cout << left << " " << right << endl;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (left >= right)
    {
        return head;
    }
    ListNode *temp = reverseBetween(head, NULL, head, NULL, head, 1, left, right);
    return temp;
}

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

//* Start with 1 to k and just add k in each iterations :)
ListNode *reverseKGroup(ListNode *head, int k)
{
    int left = 1, right = k;
    int sizeL = lenList(head);
    while (left <= sizeL && right <= sizeL)
    {
        head = reverseBetween(head, left, right);
        left += k;
        right += k;
    }
    return head;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}