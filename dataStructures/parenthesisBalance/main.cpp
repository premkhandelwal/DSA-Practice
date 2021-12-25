#include <iostream>
#include <string>
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

void push(Stack **s, char element)
{
    (*s)->top++;
    (*s)->arr[(*s)->top] = element;
}

char pop(Stack **s)
{
    char ele = (*s)->arr[(*s)->top];
    (*s)->top--;
    return ele;
}

int isMatch(char a, char b)
{
    if(a == '(' && b == ')')
    {
        return 1;
    }
    else if(a == '[' && b == ']')
    {
        return 1;
    }
    else if(a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int isBalanced(Stack *s, string expression)
{
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            if (isFull(s))
            {
                return 0;
            }
            push(&s, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            else
            {
                char poppedEle = pop(&s);
                if (!isMatch(poppedEle, expression[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    return 0;
}

int main()
{
    string exp;
    cout << "Please enter the expression: " << endl;
    getline(cin, exp);
    Stack *s = new Stack();
    s->top = -1;
    s->size = exp.length();
    s->arr = (char *)malloc(s->size * sizeof(char *));

    int isBalancedExp = isBalanced(s, exp);
    if (isBalancedExp)
    {
        cout << "Expression is balanced" << endl;
    }
    else
    {
        cout << "Expression is unbalanced" << endl;
    }
    return 0;
}

/* 8+(4 + 5+8)) */