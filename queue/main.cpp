#include <iostream>

using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(Queue* q)
{
    if(q->rear >= q->size -1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue* q)
{
    if(q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

int enqueue(Queue** q, int element)
{
    if(isFull((*q))){
        cout<< "(*Q)ueue overflow" <<endl;
        return -1;
    }
    (*q)->rear++;
    (*q)->arr[(*q)->rear] = element;
    return 1;
}

int dequeue(Queue** q)
{
    //Front is always (front-1)th element
    if(isEmpty((*q)))
    {
        cout<< "Queue underflow" <<endl;
        return -1;
    }
    (*q)-> front++;
    return (*q)->arr[(*q)->front];

}

int main()
{
    Queue *q = new Queue();
    q->size = 4;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int *));
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 17);
    enqueue(&q, 18);
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
    cout<<dequeue(&q)<<endl;
    enqueue(&q, 13);

    if(isEmpty(q))
    {
        cout<< "Queue is Empty" <<endl;
    }
    if(isFull(q))
    {
        cout<< "Queue is Full" <<endl;
    }

    return 0;
}