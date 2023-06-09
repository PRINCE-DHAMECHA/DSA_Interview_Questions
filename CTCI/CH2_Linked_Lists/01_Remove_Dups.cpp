//& Question:  Write code to remove duplicate from an unsorted linked list.

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

//~ Approach:1 :- Map
//* We use map to remember count

void deleteDups(Node *head)
{
    map<int, int> mp;
    Node *prev = NULL;
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (mp[curr->data] != 0)
        {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else
        {
            mp[curr->data]++;
            prev = curr;
            curr = curr->next;
        }
    }
}

//~ Approach:2 :- Without Extra space O(N^2)
//* We use two pointer, one will be fixed and other check all subsequent node for duplicity

void deleteDups2(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *runner = curr;
        while (runner->next != NULL)
        {
            if (runner->next->data == curr->data)
            {
                Node *prev = runner->next;
                runner->next = runner->next->next;
                free(prev);
            }
            runner = runner->next;
        }
        curr = curr->next;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;
    Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    printList(head);
    deleteDups2(head);
    printList(head);
    return 0;
}