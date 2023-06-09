//& Question:  Partition given list around x such that all node with value less than x will be left side and others are on right side.

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

//~ Approach
//* We create two list using 4 variable and merge this two list after

Node *partition(Node *node, int x)
{
    Node *beforeStart = NULL;
    Node *beforeEnd = NULL;
    Node *afterStart = NULL;
    Node *afterEnd = NULL;
    while (node != NULL)
    {
        Node *next = node->next;
        node->next = NULL;
        //* if x>node->data, insert in before list
        if (node->data < x)
        {
            //* First node
            if (beforeStart == NULL)
            {
                beforeStart = node;
                beforeEnd = beforeStart;
            }
            else
            {
                beforeEnd->next = node;
                //* Now before end will point to last node of before list
                beforeEnd = node;
            }
        }
        else
        {
            if (afterStart == NULL)
            {
                afterStart = node;
                afterEnd = afterStart;
            }
            else
            {
                afterEnd->next = node;
                afterEnd = node;
            }
        }
        node = next;
    }
    //* If no element less than x are there
    if (beforeStart == NULL)
    {
        return afterStart;
    }
    beforeEnd->next = afterStart;
    return beforeStart;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head = NULL;
    push(&head, 7);
    push(&head, 11);
    push(&head, 11);
    push(&head, 1);
    push(&head, 10);
    push(&head, 100);
    push(&head, 8);
    printList(head);
    head = partition(head, 10);
    printList(head);
    return 0;
}
