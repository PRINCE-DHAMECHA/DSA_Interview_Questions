//& Question:  You are given two linked list where each node represent a digit. Write a code that add such two list as below:-
//& (7->1->6)+(5->9->2)=(2->1->9) //First digit is least significant

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

Node *addLists(Node *l1, Node *l2, int carry)
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
        val += l1->data;
    }
    if (l2 != NULL)
    {
        val += l2->data;
    }
    //* create new node with summation obtained as above
    Node *res = new Node(val % 10);
    //* if either list is remaining recursively add
    //* Remember we are checking l1 and l2 to be null not it's next to be null because we need to add carry of this iteration which will ignored if we compare next to null because then we don't recurse for carry 1
    if (l1 != NULL || l2 != NULL)
    {
        Node *more = addLists(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, val >= 10 ? 1 : 0);
        res->next = more;
    }
    return res;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head1 = NULL;
    push(&head1, 7);
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    printList(head1);
    Node *head2 = NULL;
    push(&head2, 3);
    push(&head2, 5);
    push(&head2, 8);
    printList(head2);
    Node *head = addLists(head1, head2, 0);
    printList(head);
    return 0;
}
