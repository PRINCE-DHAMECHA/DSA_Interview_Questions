//& Question:  Check if two lino linked list is intersect or node. Return intersected node. Note that node should be exact same not just the values.

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

//* Determining:- Intersecting lists have always same end node
//* How to find intersecting node?
//* We can obtain length of both list when we reach at tail and then chop off bigger list to make same length

class Result
{
public:
    Node *tail;
    int size;
    Result(Node *tail, int size)
    {
        this->tail = tail;
        this->size = size;
    }
};

Result *getTailAndSize(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    int size = 1;
    Node *curr = head;
    while (curr->next != NULL)
    {
        size++;
        curr = curr->next;
    }
    return new Result(curr, size);
}

Node *getKthNode(Node *head, int k)
{
    Node *curr = head;
    while (k > 0 && curr != NULL)
    {
        curr = curr->next;
        k--;
    }
    return curr;
}

Node *findIntersection(Node *l1, Node *l2)
{
    if (l1 == NULL || l2 == NULL)
    {
        return NULL;
    }
    //* Get tail of both node and size
    Result *r1 = getTailAndSize(l1);
    Result *r2 = getTailAndSize(l2);
    //* if tail is not same
    if (r1->tail != r2->tail)
    {
        return NULL;
    }
    //* find longer and shorter list
    Node *shorter = r1->size < r2->size ? l1 : l2;
    Node *longer = r1->size < r2->size ? l2 : l1;
    //* skip required node from longer
    longer = getKthNode(longer, abs(r1->size - r2->size));
    //* start traversing together
    //* as tail is same for both there must be a intersection
    while (shorter != longer)
    {
        shorter = shorter->next;
        longer = longer->next;
    }
    //* return any
    return longer;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head = NULL;
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);
    push(&head, 9);
    push(&head, 14);
    Node *head2 = NULL;
    push(&head2, 2);
    head2->next = head->next->next;
    printList(head);
    printList(head2);
    cout << (findIntersection(head, head2))->data << endl;
    return 0;
}
