//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *arr;
};

Queue *createQueue(unsigned capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = new int[capacity - 1];
    return queue;
}

bool isFull(Queue *q)
{
    return q->size == q->capacity;
}

bool isEmpty(Queue *q)
{
    return q->size == 0;
}

void enqueue(Queue *q, int x)
{
    if (isFull(q))
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->size += 1;
    return;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue Underflow" << endl;
        return INT_MIN;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size -= 1;
    return item;
}

int front(Queue *q)
{
    if (isEmpty(q))
    {
        return INT_MIN;
    }
    return q->arr[q->front];
}

int rear(Queue *q)
{
    if (isEmpty(q))
    {
        return INT_MIN;
    }
    return q->arr[q->rear];
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    Queue *queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout << dequeue(queue) << " dequeued from queue\n";
    cout << "Front item is " << front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;
    return 0;
}

//~ Advantages of Array Implementation:
//* Easy to implement.
//* A large amount of data can be managed efficiently with ease.
//* Operations such as insertion and deletion can be performed with ease as it follows the first in first out rule.

//~ Disadvantages of Array Implementation:
//* Static Data Structure, fixed size.
//* If the queue has a large number of enqueue and dequeue operations, at some point (in case of linear increment of front and rear indexes) we may not be able to insert elements in the queue even if the queue is empty (this problem is avoided by using circular queue).
//* Maximum size of a queue must be defined prior.