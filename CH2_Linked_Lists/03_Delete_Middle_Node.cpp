//& Question:  Delete a node in Middle Node(Not necessary exact middle).  i.e. delete given intermidiate node.

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

bool deleteNode(Node *n)
{
    if (n == NULL || n->next == NULL)
    {
        return false;
    }
    //* We are not given prev node so how can we point prev to curr->next?
    //* we copy data from next to curr and delete next //* Hypocrisy
    //* Remember this will fail for last node so discuss it with interviewer
    //* This is only approach because we don't have access to head node
    Node *next = n->next;
    n->data = next->data;
    n->next = next->next;
    free(next);
    return true;
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
    deleteNode(head->next->next);
    printList(head);
    return 0;
}