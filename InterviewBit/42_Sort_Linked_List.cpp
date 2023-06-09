//& Write a function to sort a linked list of 0s, 1s and 2s

//~ Input: 0->1->0->2->1->0->2->1
//~ Output: 0->0->0->1->1->1->2->2

//& Explanation: All 0’s will come first then 1s and then 2s. This can be done in O(n) time by counting the occurrences of all three and rearranging them in the linked list.

//^ Solution:

//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void push(Node **headRef, int newData)
{
    Node *newNode = new Node(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

//~ Approach:
//* Iterate through list and count occurrences of 0,1 and 2
//* Pretty much straight forward

void sortList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        if (temp->data == 1)
        {
            oneCount++;
        }
        if (temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while (zeroCount--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (oneCount--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (twoCount--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 0);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    printList(head);
    sortList(head);
    printList(head);
    return 0;
}