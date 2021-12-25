#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(Node *top)
{
    Node *p = new Node();
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

Node *push(Node *top, int element)
{
    if (isFull(top))
    {
        cout << "Stack Overflow" << endl;
    }
    Node *ptr = new Node();
    ptr->data = element;
    ptr->next = top;
    top = ptr;
    return ptr;
}

Node *pop(Node **top)
{
    if (isEmpty(*top))
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Node *ptr = (*top);
        int data = (*top)->data;
        *top = (*top)->next;
        free(ptr);
        return *top;
    }
}

int peek(Node *top, int position)
{
    Node *ptr = top;
    int i = 0;
    while (i < position-1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL)
    {
        cout << "Invalid Position" << endl;
        return -1;
    }
    return ptr->data;
}

int stackTop(Node *top)
{
    return top->data;
}

int stackBottom(Node *top)
{
    while (top->next != NULL)
    {
        top = top->next;
    }
    return top->data;
}

void traversal(Node *head)
{
    while (head != NULL)
    {

        cout << "data " << head->data << endl;
        head = head->next;
    }
}

int main()
{
    Node *top = NULL;
    top = push(top, 78);
    top = push(top, 28);
    cout << "Before pop: " << endl;
    traversal(top);
    // top = pop(&top);
    cout << "After pop: " << endl;

    // cout<< "Popped element: " << pop(top) <<endl;
    traversal(top);

    for (int j = 1; j <= 3; j++)
    {
        cout<< "Element at position " << j << " is " << peek(top, j) <<endl;
    }

    return 0;
}