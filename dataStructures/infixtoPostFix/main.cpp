#include <iostream>
#include <string>
// #include <string.h>

using namespace std;

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isFull(Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    /* * / , + - */
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    return 0;
}

int isOperator(char ch)
{
    if (ch == '%' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

void push(Stack **s, char element)
{
    if (isFull((*s)))
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    else
    {
        (*s)->top++;
        (*s)->arr[(*s)->top] = element;
    }
}

char pop(Stack **s)
{
    if (isEmpty((*s)))
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        int ele = (*s)->arr[(*s)->top];
        (*s)->top--;
        return ele;
    }
}

char stackTop(Stack *s)
{
    return s->arr[s->top];
}

char *infixToPostFix(Stack *s, string infix)
{
    char *postFix = (char *)malloc((infix.length() + 1) * sizeof(char *)); // Initialize array to return postfix expression
    int i = 0;                                                            // Track infix expression
    int j = 0;                                                            // Track postfix addition
    while (infix[i] != '\0')                                              // While string is not emoty
    {
        if (!isOperator(infix[i]))
        {
            postFix[j] = infix[i]; // If val is an operand add it to postfix array
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(s)))
            {
                // If incoming operand is of higher precedence than the operand already sitting in the stack, push the element in the stack
                push(&s, infix[i]);
                i++; // Take the next char from infix expression
            }
            else
            {
                postFix[j] = pop(&s); // Pop element from the stack and append to postfix
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        postFix[j] = pop(&s);
        j++;
    }
     postFix[j] ='\0';
     return postFix;
    
}

int main()
{
string exp;
    cout << "Please enter the expression: " << endl;
    getline(cin,exp);
    // char* rew = exp;
    Stack *s = new Stack();
    s->top = -1;
    s->size = exp.length();
    s->arr = (char *)malloc(s->size * sizeof(char *));

    cout<< "The postfix of given expression is " << infixToPostFix(s, exp) <<endl;
    return 0;
}