#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversal(Node *head)
{
    Node *ptr = head;
    cout << "Data: " << ptr->data << endl;

    ptr = ptr->next;
    do
    {
        cout << "Data: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node *insertatBeginning(Node *head, int data)
{
    Node *p = head->next;
    Node *ptr = new Node();
    while (p->next != head)
    {
        cout << "hello" << endl;
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->data = 7;
    head->next = second;

    second->data = 70;
    second->next = third;

    third->data = 700;
    third->next = fourth;

    fourth->data = 7000;
    fourth->next = head;

    // traversal(head);

    // ?Insert at beginning
    cout << "Linked list: " << endl;
    traversal(head);

    head = insertatBeginning(head, 6);
    // fourth->next = head;
    cout << "Modified Linked list: " << endl;
    traversal(head);

    return 0;
}