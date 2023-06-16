//& You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

//& You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
//* https://github.com/PRINCE-DHAMECHA/DSA_Interview_Questions/blob/main/CTCI/CH2_Linked_Lists/05_Sum_Lists.cpp

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0)
{
    //* If nothing left return null
    if (l1 == NULL && l2 == NULL && carry == 0)
    {
        return NULL;
    }
    //* add carry
    int val = carry;
    //* add l1 and l2 node is not null
    if (l1 != NULL)
    {
        val += l1->val;
    }
    if (l2 != NULL)
    {
        val += l2->val;
    }
    //* create new node with summation obtained as above
    ListNode *res = new ListNode(val % 10);
    //* if either list is remaining recursively add
    //* Remember we are checking l1 and l2 to be null not it's next to be null because we need to add carry of this iteration which will ignored if we compare next to null because then we don't recurse for carry 1
    if (l1 != NULL || l2 != NULL)
    {
        ListNode *more = addTwoNumbers(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, val >= 10 ? 1 : 0);
        res->next = more;
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}