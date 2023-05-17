//& Question:  Find kth Node from end.

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

//* O(1)
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
}

//~ Approach:1
//* Iterative way
//* index from 1 to n
//* i.e. 1->Last element
Node *getNthEnd(Node *head, int index)
{
    int len = 0;
    Node *temp = head;
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

//~ Approach:2
//* Recursive
Node *getNthEndRec(Node *head, int index)
{
    static int i = 0;
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = getNthEndRec(head->next, index);
    i++;
    //* If we reach at nth from end then return this node
    if (i == index)
    {
        return head;
    }
    //* else return from node we get from recursion
    return temp;
}

//~ Approach:3
//* Two Pointer
//* Move first pointer to nth place and now move both pointer together, When first pointer hits end bingo second pointer will be at kth node from last

Node *getNthEnd2PTR(Node *head, int index)
{
    Node *p1 = head;
    Node *p2 = head;
    for (int i = 0; i < index; i++)
    {
        //* Corner case when index > size
        if (p1 == NULL)
        {
            return NULL;
        }
        p1 = p1->next;
    }
    while (p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 8);
    push(&head, 10);
    push(&head, 11);
    push(&head, 100);
    printList(head);
    cout << endl;
    cout << getNthEndRec(head, 6)->data << endl;
    cout << getNthEnd2PTR(head, 3)->data << endl;
    return 0;
}