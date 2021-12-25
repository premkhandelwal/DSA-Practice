#include <iostream>

using namespace std;

struct CircularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(CircularQueue* cq)
{
    if ((cq->rear + 1) % cq->size == cq->front)
    {
        return 1;
    }
    return 0;
}

int isEmpty(CircularQueue** cq)
{
    if((*cq)->front == (*cq)->rear)
    {
        return 1;
    }
    return 0;

}

void enqueue(CircularQueue** cq, int data)
{
    if(isFull((*cq)))
    {
        cout<< "Queue overflow" <<endl;
    }
    else
    {
        (*cq)->rear = ((*cq)->rear + 1) % (*cq)->size;
        (*cq)->arr[(*cq)->rear] = data;
        cout<< "Enqueued: " << data <<endl;

    }
}

int dequeue(CircularQueue** cq)
{
    if(isEmpty(cq)){
        cout<< "Queue underflow" <<endl;
        return -1;
    }
    else
    {
        (*cq)->front = ((*cq)->front + 1) % (*cq)->size;
        return (*cq)->arr[(*cq)->front];
    }
}

int main()
{
    CircularQueue *q = new CircularQueue();
    q->size = 4;
    q->front = q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int *));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 20);

    cout<< "Dequeued element: " << dequeue(&q) <<endl;
    cout<< "Dequeued element: " << dequeue(&q) <<endl;
    cout<< "Dequeued element: " << dequeue(&q) <<endl;
    // cout<< "Dequeued element: " << dequeue(&q) <<endl;
    enqueue(&q, 20);

    if(isEmpty(&q))
    {
        cout<< "Queue is Empty" <<endl;
    }
    if(isFull(q))
    {
        cout<< "Queue is Full" <<endl;
    }
    return 0;
}