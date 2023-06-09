//& Question:  Check if there's any loop in linked list. If there's one return starting node of loop.

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

Node *findLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    //* After this fast and slow will be k nodes away from starting node of loop
    //* suppose non loop is k size
    //* so when slow traverse k nodes fast traverse 2k
    //* now fast will be k nodes in loop
    //* now fast is behind slow by loop-k nodes
    //* fast will be closer by 1 node in each step
    //* now after loop-k steps fast==slow
    //* now both will be k node away from start node of the loop
    //* see as perspective of slow -> 1. (k) to reach start 2. (loop-k) to slow==fast
    //* now where is slow? k+loop-k=loop nodes from beginning
    //* now after k nodes -> loop+k (1 full cycle)
    //* below step adds loop steps so slow=fast and then we place slow at head and when again slow=fast i.e. after k steps that node will be our start node of loop
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    //* If there's no loop
    if (fast == NULL || fast->next == NULL)
    {
        return NULL;
    }
    //* Add k steps
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Node *head = NULL;
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);
    push(&head, 9);
    push(&head, 15);
    push(&head, 16);
    push(&head, 12);
    push(&head, 17);
    printList(head);
    head->next->next->next->next->next->next->next = head->next->next->next; //* loop from last to on node with value 15
    cout << findLoop(head)->data << endl;
    return 0;
}
