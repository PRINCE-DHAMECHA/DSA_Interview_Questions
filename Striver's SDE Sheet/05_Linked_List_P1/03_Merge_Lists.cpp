//& Merge given two sorted linked list.

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
//* Pretty much merger sort's merge function

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if (list1 == NULL || list2 == NULL)
    {
        return list1 != NULL ? list1 : list2;
    }
    ListNode *head = NULL, *headRef = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            ListNode *temp = new ListNode(list1->val);
            if (head != NULL)
            {
                head->next = temp;
                head = head->next;
                list1 = list1->next;
            }
            else
            {
                headRef = temp;
                head = temp;
                list1 = list1->next;
            }
        }
        else
        {
            cout << list1->val << " " << list2->val << endl;
            ListNode *temp = new ListNode(list2->val);
            if (head != NULL)
            {
                head->next = temp;
                head = head->next;
                list2 = list2->next;
            }
            else
            {
                headRef = temp;
                head = temp;
                list2 = list2->next;
            }
        }
    }
    while (list1 != NULL)
    {
        ListNode *temp = new ListNode(list1->val);
        if (head != NULL)
        {
            head->next = temp;
            head = head->next;
            list1 = list1->next;
        }
        else
        {
            headRef = head = temp;
        }
    }
    while (list2 != NULL)
    {
        ListNode *temp = new ListNode(list2->val);
        if (head != NULL)
        {
            head->next = temp;
            head = head->next;
            list2 = list2->next;
        }
        else
        {
            headRef = head = temp;
        }
    }
    return headRef;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}