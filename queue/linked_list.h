#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value = 0)
    {
        data = value;
        next = NULL;
    }
};
void push_front(node *&headptr, int new_value)
{
    node *new_head = new node(new_value);
    new_head->next = headptr;
    headptr = new_head;
}
void push_back(node *&headptr, int new_value)
{
    node *ptr = headptr;
    if (headptr == NULL)
    {
        headptr = ptr;
        return;
    }
    node *temp = headptr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *tail = new node(new_value);
    temp->next = tail;
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void reverse(node *&head)
{
    node *prev = NULL;
    node *cur = head;
    node *next = NULL;
    while (cur->next != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    cur->next = prev;
    head = cur;
}

void insert(node *&head, int element, int index)
{
    node *temp = new node(0);
    node *ins = new node(element);
    temp = head;
    while (index > 1)
    {
        temp = temp->next;
    }
    ins->next = temp->next;
    temp->next = ins;
}

void pop_back(node *&head)
{
    if (head == NULL)
    {
        cout << "empty list" << endl;
        return;
    }
    if (head->next == NULL)
    {
        // delete head;
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void pop_front(node* &head)
{
    head=head->next;
}

node *merge(node *a, node *b)
{
    node *temp;
    node *ans = new node;
    temp = ans;
    while (a != NULL && b != NULL)
    {
        if (a->data >= b->data)
        {
            temp->next = b;
            temp = temp->next;
            b = b->next;
        }
        else
        {
            temp->next = a;
            temp = temp->next;
            a = a->next;
        }
    }
    if (a != NULL)

        temp->next = a;

    if (b != NULL)

        temp->next = b;

    return (ans->next);
}
node *createlist(int arr[], int n)
{
    node *head = new node(arr[0]);
    for (int i = 1; i < n; i++)
    {
        push_back(head, arr[i]);
    }
    return head;
}
