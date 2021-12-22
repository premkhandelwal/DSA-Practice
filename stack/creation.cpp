#include <iostream>

using namespace std;

struct Stack
{
    int size;
    int top;
    int *arr;
};

bool isEmpty(Stack *ptr)
{
    return ptr->top == -1;
}

bool isFull(Stack *ptr)
{
    return ptr->top >= ptr->size - 1;
}

void push(Stack *stack, int element)
{
    if (isFull(stack))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        stack->top++;
        stack->arr[stack->top] = element;
    }
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        int val = stack->arr[stack->top];
        stack->top--;
        return val;
    }
}

int peek(Stack* stack, int i)
{
    int val = stack->top-i+1;
    if(val<0)
    {
        cout << "Invalid Position" << endl;
        return -1;
    }
    else
    {
        return stack->arr[val];
    }
}

int stackTop(Stack* stack)
{
    return stack->arr[stack->top];
}

int stackBottom(Stack* stack)
{
    return stack->arr[0];
}

int main()
{
    Stack *s = new Stack();
    s->size = 5;
    s->top = -1;
    s->arr = new int;
    /* s->arr[0] = 4;
    s->top++; */
  

    /* cout << "Popped Elemtent" << pop(s) << endl;
    cout << "Popped Elemtent" << pop(s) << endl;

    cout << "After popping" << endl;
    cout << "Array is empty? " << isEmpty(s) << endl;
    cout << "Array is full? " << isFull(s) << endl; */
    push(s, 5);
    push(s, 52);
    push(s, 3);

    push(s, 42);
    push(s, 4);
    for (int j = 1; j <= s->top+1; j++)
    {
        cout<< "Element at position " << j << " is " << peek(s, j) <<endl;
    }
    

    cout << "Stack Top: " << stackTop(s) << endl; 
    cout << "Stack Bottom: " << stackBottom(s) << endl; 

    return 0;
}