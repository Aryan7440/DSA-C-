#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void pushback(node *&head, int x)
{
    node *newtail = new node;
    newtail->data = x;
    newtail->next = NULL;
    if (head == NULL)
    {
        head = newtail;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newtail;
}
node *merge(node *a, node *b)
{
    node *ans = new node;
    node *temp;
    // ans = temp;
    temp = ans;
    // temp = temp->next;
    // node**link;
    // *link=ans;
    while (a != NULL && b != NULL)
    {
        if (a->data >= b->data)
        {
            temp->next = b;
            b = b->next;
        }
        else
        {
            temp->next = a;
            a = a->next;
        }
        temp = temp->next;
    }
    if (a == NULL)

        temp->next = b;

    else
        temp->next = a;

    return ans->next;
}

node *linkmerge(node *a, node *b)
{
    node *temp;
    node **link;
    link = &temp;

    // **link=*temp;
    while (a != NULL && b != NULL)
    {
        if (a->data >= b->data)
        {
            // temp = b;
            *link = b;
            link = &(*link)->next;
            b = b->next;
        }
        else
        {
            // temp = a;
            *link = a;
            link = &(*link)->next;
            a = a->next;
        }
        // temp = temp->next;
    }
    // if (a == NULL)

    // { // temp = b;
    //     *link = b;
    // }

    // if (b == NULL)
    // { // temp = a;
    //     *link = a;
    // }

    // return ans->next;
    *link = (a) ? a : b;
    return temp;
}

node *mergeRec(node *a, node *b)
{
    node *res = NULL;
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    if (a->data > b->data)
    {
        res=b;
        res->next=mergeRec(a,b->next);
        // b->next = mergeRec(a, b->next);
        // return b;
    }
    else
    {
        res=a;
        res->next=mergeRec(a->next,b);
        // a->next = mergeRec(a->next, b);
        // return a;
    }
    return res;
}

int main()
{
    node *first = new node;
    first = NULL;
    node *second = new node;
    second = NULL;
    pushback(first, 1);
    pushback(first, 3);
    pushback(first, 5);
    pushback(second, 2);
    pushback(second, 4);
    pushback(second, 6);
    display(first);
    display(second);
    // node *n = merge(first, second);
    // display(n);
    node *M = mergeRec(first, second);
    display(M);
    // pushback(n,45);
    // display(n);
    display(first);
    display(second);
}