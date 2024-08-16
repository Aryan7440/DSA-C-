#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

node* ins(node* head,node* tail)
{
    if(head==NULL)
    {
        return tail;
    }
   else
   {
     head->next=ins(head->next,tail);
     return head;
   }
}
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

node* insert_recursion(node* &head,int x,int i)
{
    if(i==0)
    {
        node* new_head=new node(x);
        new_head->next=head;
        return new_head;
    }
    head->next=insert_recursion(head->next,x,i-1);
    return head;
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

int main()
{
    int arr1[] = {1, 3, 5, 7, 11};
    int arr2[] = {0, 2, 4, 6, 8, 11, 13};
    node *head = createlist(arr1, 5);
    node *head2 = createlist(arr2, 7);
    display(head);
    head=insert_recursion(head,69,3);
    display(head);
    // push_back(head,89);
    // node* t=new node(69);
    // node* h3=ins(head,head2);
    // display(h3);

    // display(head2);
    // node *mergelist = new node;
    // mergelist = merge(head, head2);
    // display(mergelist);
    // reverse(mergelist);
    // display(mergelist);
}