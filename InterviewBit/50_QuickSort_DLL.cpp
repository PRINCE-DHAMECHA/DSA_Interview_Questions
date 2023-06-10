//& Write a function to implement Quicksort on Doubly Linked List.

//* Quick Sort

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
    Node *prev;
    int data;
    Node *next;
    Node(int val)
    {
        prev = NULL;
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node **headRef, int val)
{
    Node *n = new Node(val);
    //* New head->next = old head
    n->next = *headRef;
    if (*headRef != NULL)
    {
        //* old head->prev=new head
        (*headRef)->prev = n;
    }
    //* set new head
    *(headRef) = n;
}

Node *lastNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    else
    {
        return lastNode(head->next);
    }
}

Node *part(Node *l, Node *h)
{
    //* Pivot
    Node *temp = h;
    //* j
    Node *tt = l;
    //* i
    Node *first = l;
    while (tt != h)
    {
        //* If less than  pivot than add in beginning means at first
        if (tt->data <= temp->data)
        {
            swap(first->data, tt->data);
            first = first->next;
        }
        tt = tt->next;
    }
    //* set position of pivot
    swap(first->data, h->data);
    return first;
}

void QSList(Node *l, Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Node *p = part(l, h);
        QSList(l, p->prev);
        QSList(p->next, h);
    }
}

void QSWrapper(Node *head)
{
    Node *h = lastNode(head);
    QSList(head, h);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Node *head = NULL;
    insertAtHead(&head, 1);
    insertAtHead(&head, 4);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);
    QSWrapper(head);
    printList(head);
    return 0;
}