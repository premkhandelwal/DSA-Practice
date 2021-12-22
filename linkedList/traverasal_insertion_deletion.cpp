#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insertatBeginning(Node* head, int data){
    Node* ptr = new Node();
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

void insertatIndex(Node* head, int data, int index){
    Node* ptr = new Node();
    Node* p = head;
    int i = 0; 
    while (i != index -1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

void insertatEnd(Node* head, int data){
    Node* ptr = new Node();
    Node* p = head;
    int i = 0; 
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
}

void insertAfterNode(Node* head, int data, Node* node){
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = node->next;
    node->next = ptr;
}

Node* deletionatBeginning(Node* head){
    Node* ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}

void deletionatIndex(Node* head, int index){
    /* Node*  ptr = head;
    int i = 0;
    while (i != index -1)
    {
        ptr = ptr -> next;
        i++;
    }
    Node* q = ptr->next;
    ptr->next = q->next;
    free(q); */

    Node *p = head;
    Node* q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    
}

void deletionatEnd(Node* head){
    /* Node* p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    Node* q = p->next;
    p->next =  NULL;
    free(q); */

    Node* p = head;
    Node* q = head -> next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    
}

void deletionatValue(Node* head, int value){
    Node *p = head;
    Node* q = head->next;
    while (q->data != value && q->next != NULL )
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value){

    p->next = q->next;
    free(q);
    }
    
}

void traversal(Node* head){
    while (head != NULL)
    {
    
    cout<< "data " << head ->data <<endl;
    head = head->next;
    }
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 7;
    head->next = second;
    
    second->data = 70;
    second->next = third;
    
    third->data = 700;
    third->next = NULL;

    //? Traversal
    // traversal(head);

    //? Insertion at beginning
    /* head =insertatBeginning(head, 56);
    traversal(head); */

    //? Insertion at Index
    /* insertatIndex(head, 140, 0);
    traversal(head);  */  

    //? Insertion at End
    /* insertatEnd(head, 140);
    traversal(head); */

    //? Insertion after Node
    /* insertAfterNode(head, 2, second);
    traversal(head); */

    //? Deletion at beginning
    /* cout<< "Linked list: " << endl;
    traversal(head);

    head = deletionatBeginning(head);
    cout<< "Modified Linked list: " << endl;
    traversal(head); */

    //? Deletion at index
    /* cout<< "Linked list: " << endl;
    traversal(head);

    deletionatIndex(head, 1);
    cout<< "Modified Linked list: " << endl;
    traversal(head); */
    
    //? Deletion at end
    /* cout<< "Linked list: " << endl;
    traversal(head);

    deletionatEnd(head);
    cout<< "Modified Linked list: " << endl;
    traversal(head); */

    //? Deletion at value
    /* cout<< "Linked list: " << endl;
    traversal(head);

    deletionatValue(head, 701);
    cout<< "Modified Linked list: " << endl;
    traversal(head); */
    
    return 0;
}