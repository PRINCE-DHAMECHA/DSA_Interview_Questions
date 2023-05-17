//& Question:  Check if a linked list is a palindrome.

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

//~ Approach:1 :- Reverse and Compare

Node *reverseAndClone(Node *node)
{
    Node *head = NULL;
    while (node != NULL)
    {
        Node *n = new Node(node->data);
        //* Make new node->next as head
        n->next = head;
        //* Shift head to new node
        head = n;
        //* process next node
        node = node->next;
    }
    return head;
}

bool isEqual(Node *one, Node *two)
{
    while (one != NULL && two != NULL)
    {
        if (one->data != two->data)
        {
            return false;
        }
        one = one->next;
        two = two->next;
    }
    return one == NULL & two == NULL;
}

bool isPal(Node *head)
{
    Node *reversed = reverseAndClone(head);
    return isEqual(head, reversed);
}

//~ Approach:2 :- Iterative

bool isPalin(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    stack<int> st;
    while (fast != NULL && fast->next != NULL)
    {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    //* Case for odd number of nodes
    if (fast != NULL)
    {
        slow = slow->next;
    }
    while (slow != NULL)
    {
        int top = st.top();
        st.pop();
        if (top != slow->data)
        {
            return false;
        }
        slow = slow->next;
    }
    return true;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head = NULL;
    push(&head, 7);
    push(&head, 8);
    push(&head, 5);
    // push(&head, 8);
    push(&head, 7);
    printList(head);
    cout << isPal(head) << endl;
    cout << isPalin(head) << endl;
    return 0;
}
