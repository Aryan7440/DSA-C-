#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Create A class node

class node
{
public:
    int data;
    node *next;

    // Node Class Constructor
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert Element At Tail

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Display All Element

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insert At Head

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insert_at_pos(node *head,int val,int pos)
{
    node *temp=head;
    int i=1;
    while (i<pos)
    {
        temp=temp->next;
        i++;
    }
    
    node *n=new node(val);
    n->next=temp->next;
    temp->next=n;
}

// Seraching  At Linked List

bool Search(node *head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 12);
    insertAtTail(head, 178);
    insertAtTail(head, 1788);
    // display(head);

    // cout<<head<<endl;
    // cout<<&head<<endl;
    // cout<<head->next<<endl;
    // printf("%d \n",head);
    // printf("%d \n",&head);
    // printf("%d \n",*&head);

    // printf("%d \n",head->next->next);
    // printf("%d \n",sizeof(node));
    insertAtHead(head, 345);
    insertAtHead(head, 3);
    insertAtHead(head, 35);
    insertAtHead(head, 745);
    insertAtHead(head, 3545);
    
    display(head);
    // cout << Search(head, 178);

    insert_at_pos(head,67,6);
    display(head);
    cout<<head->data<<endl;
    cout<<head->next->data<<endl;
    cout<<head->next->next->data<<endl;
    cout<<head->next->next->next->data<<endl;

    return 0;
}

// Output -
//     12->178->1788->NULL 345->12->178->1788->NULL 1