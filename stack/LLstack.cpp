#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push(int x)
{
    struct node *new_head = new node;
    if (new_head == NULL)
    {
        cout << "stack overflow" << endl;
        return;
    }
    new_head->data = x;
    new_head->next = top;
    top = new_head;
}

int pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "empty stack" << endl;
        return x;
    }
    node *ptr = top;
    top->data = x;
    top = top->next;
    delete ptr;
}

bool isempty()
{
    return top == NULL;
}

void showtop()
{
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        return;
    }

    cout << top->data << endl;
}
void display()
{
    node* temp;
    if (top == NULL)
    {
        cout << "\nStack empty";
        return;
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

int main()
{
    push(0);
    push(1);
    push(2);
    push(3);
    push(4);
    push(4);
    display();
    pop();
    showtop();
    pop();
    showtop();
    display();
    pop();
    pop();
    pop();
    pop();
    (isempty())? cout<<"empty"<<endl : cout<<"NOT empty"<<endl;
}
