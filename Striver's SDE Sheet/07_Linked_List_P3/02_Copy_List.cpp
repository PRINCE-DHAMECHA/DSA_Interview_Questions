//& Copy given list which has random links also.

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

struct Node
{
    int val;
    Node *next;
    Node *random;
    Node() : val(0), next(nullptr), random(nullptr) {}
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *next, Node *random) : val(x), next(next), random(random) {}
};

//~ Approach:
//* We first make duplicate list using only next and then we start from beginning and count how far random node from start and we went that far and assign it to random current node of new list.

Node *copyRandomList(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = new Node(head->val);
    Node *headNew = temp;
    Node *tempHead = head;
    //* Copy list with only next
    while (tempHead != NULL)
    {
        Node *newNode = new Node(tempHead->val);
        temp->next = newNode;
        temp = temp->next;
        newNode->next = tempHead->next;
        tempHead = tempHead->next;
    }
    //* Start from head of both list
    //* Find how far is the random node of current node in old list from head
    //* Go that far in new list
    Node *headOld = head, *tempHeadNew = headNew->next;
    while (headOld != NULL)
    {
        if (headOld->random != NULL)
        {
            int count = 0;
            Node *start = head, *end = headOld->random;
            while (start != end)
            {
                start = start->next;
                count++;
            }
            Node *startNew = headNew->next;
            while (count--)
            {
                startNew = startNew->next;
            }
            tempHeadNew->random = startNew;
        }
        headOld = headOld->next;
        tempHeadNew = tempHeadNew->next;
    }
    return headNew->next;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    return 0;
}