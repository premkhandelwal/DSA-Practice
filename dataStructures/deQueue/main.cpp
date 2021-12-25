#include <iostream>

using namespace std;

struct DEQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(DEQueue *dq)
{
    if (dq->front == dq->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(DEQueue *dq)
{
    if (dq->rear == dq->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueueR(DEQueue **dq, int data)
{
    if (isFull((*dq)))
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        (*dq)->rear++;
        (*dq)->arr[(*dq)->rear] = data;
        cout << "Enqueued element from rear: " << data << endl;
    }
}

void enqueueF(DEQueue** dq, int data)
{
    if (isFull((*dq)))
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        (*dq)->arr[(*dq)->front] = data;
        (*dq)->front--;
        cout << "Enqueued element from front: " << data << endl;
    }
}

int dequeueF(DEQueue **dq)
{
    if (isEmpty((*dq)))
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    else
    {
        (*dq)->front++;
        return (*dq)->arr[(*dq)->front];
    }
}

int dequeueR(DEQueue **dq)
{
    if (isEmpty((*dq)))
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    else
    {
        int rear = (*dq)->rear;
        (*dq)->rear--;
        return (*dq)->arr[rear];
    }
}

void traverse(DEQueue* dq)
{
    cout<< "Traversing" <<endl;
    for (int i = 0; i < *dq->arr-1; i++)
    {
        cout<<  dq->arr[i] << " ";
    }
    
}

int main()
{
    DEQueue *dq = new DEQueue();
    dq->size = 4;
    dq->front = dq->rear = -1;
    dq->arr = (int *)malloc(dq->size * sizeof(int *));

    enqueueR(&dq, 5);
    enqueueF(&dq, 50);

    // cout << "Dequeued element: " << dequeueF(&dq) << endl;
    enqueueR(&dq, 500);
    enqueueR(&dq, 5000);
    // enqueueR(&dq, 5000);
    cout << "Dequeued element from rear: " << dequeueR(&dq) << endl;
    cout << "Dequeued element from front: " << dequeueF(&dq) << endl;
    cout << "Dequeued element from front: " << dequeueF(&dq) << endl;
    cout << "Dequeued element from front: " << dequeueF(&dq) << endl;
    // traverse(dq);
    return 0;
}