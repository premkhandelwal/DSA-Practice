#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *front;
    Node *rear;
    Node *next;
};

int isEmpty(Node *q)
{
    if (q->front == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(Node *q)
{
    if (q == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(Node **q, int data)
{
        Node *ptr = new Node();
    if (ptr == NULL)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (isEmpty((*q)))
        {
            (*q)->rear = ptr;
            (*q)->front = ptr;
        }
        else
        {
            (*q)->rear->next = ptr; // At the point of this time, rear is unchanged
            (*q)->rear = ptr;       // new node is made rear here
        }
        cout<< "Enqueued: " << data <<endl;
    }
}
int dequeue(Node **q)
{
    if (isEmpty((*q)))
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    else
    {
        Node *ptr = (*q)->front;
        (*q)->front = (*q)->front->next;
        int data = ptr->data;
        free(ptr);
        return data;
    }
}

void traversal(Node* head){
    while (head != NULL)
    {
    
    cout<< "data " << head ->data <<endl;
    head = head->next;
    }
}

int main()
{
    Node *q = new Node();
    q->front = q->rear = NULL;
    traversal(q->front);
    cout<< "Dequeued element: " << dequeue(&q) <<endl;

    enqueue(&q, 12);
    cout<< "Dequeued element: " << dequeue(&q) <<endl;
    enqueue(&q, 24);
    enqueue(&q, 36);
    traversal(q->front);
    
    cout<< "Dequeued element: " << dequeue(&q) <<endl;
    traversal(q->front);

    // cout<< "Dequeued element: " << dequeue(&q) <<endl;
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