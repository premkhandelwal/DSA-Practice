#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void traversal(Node *head)
{
    Node *p = head;

    cout << "Data Forward" << endl;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p->next != NULL);
    cout << p->data << endl;

    cout << "\nData Backward" << endl;
    do
    {
        cout << p->data << endl;
        p = p->prev;
    } while (p != NULL);
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 70;
    second->prev = head;
    second->next = third;

    third->data = 700;
    third->prev = second;
    third->next = fourth;

    fourth->data = 7000;
    fourth->prev = third;
    fourth->next = NULL;

    traversal(head);

    return 0;
}