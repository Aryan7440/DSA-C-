#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void pushback(struct node **head, int x)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next=NULL;

    if (*head == NULL)
    {
        // head->next = NULL;
        // head->data = x;
        *head=ptr;
    }

    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
    }
}

// struct node* pushfront(struct node* head,int x)
// {
//     struct node* temp=(struct node*)malloc(sizeof(struct node));
//     temp->data=x;
//     temp->next=head;
//     return temp;
// }
void pushfront(struct node **head, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void insert(struct node *head, int x, int index)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    while (index > 1)
    {
        head = head->next;
        index--;
    }
    temp->next = head->next;
    head->next = temp;
}

void reverse(struct node **head)
{
    struct node *prev = (struct node *)malloc(sizeof(struct node));
    prev = NULL;
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *Next = (struct node *)malloc(sizeof(struct node));
    Next = (*head)->next;
    curr = (*head);
    while (curr->next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = Next;
        Next = Next->next;
    }
    curr->next = prev;
    (*head) = curr;
}

void replace(struct node *head, int index, int value)
{
    while (index > 0)
    {
        head = head->next;
        index--;
    }
    head->data = value;
}

void pop(struct node *head, int index)
{
    while (index > 1)
    {
        index--;
        head = head->next;
    }
    head->next = (head->next)->next;
}

void pop_back(struct node *head)
{
    while ((head->next->next) != NULL)
    {
        head = head->next;
    }
    head->next = NULL;
}

void pop_front(struct node **head)
{
    (*head) = (*head)->next;
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
// struct node * merge_sort(struct node *a, struct node *b)
void merge_sort(struct node *a, struct node *b)
{
    struct node *ans = (struct node *)malloc(sizeof(struct node));
    ans = NULL;
    while (a->next != NULL || b->next != NULL)
    {
        if (a->data == b->data)
        {
            pushback(&ans, a->data);
            pushback(&ans, b->data);
            a = a->next;
            b = b->next;
        }
        if ((a->data > b->data) && b!=NULL)
        {
            pushback(&ans, b->data);
            b = b->next;
        }
        if ((b->data > a->data) && a!=NULL)
        {
            pushback(&ans, a->data);
            a = a->next;
        }
    }
    // return ans;
    display(ans);
}

int main()
{

    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    // struct node *third;
    // third = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = NULL;
    pushback(&head, 2);
    pushback(&head, 3);
    pushback(&head, 4);
    pushback(&head, 5);
    pushback(&head, 6);
    pushback(&head, 7);
    pushback(&head, 8);
    pushback(&head, 9);

    second->data = 10;
    second->next = NULL;
    pushback(&second, 11);
    pushback(&second, 12);
    pushback(&second, 13);
    pushback(&second, 14);
    pushback(&second, 15);
    pushback(&second, 16);
    pushback(&second, 17);
    pushback(&second, 18);
    pushback(&second, 19);
    pushback(&second, 20);

    // third->data = 3;

    // first->next = second;
    // second->next = third;
    // third->next = NULL;

    // display(head);

    // pushback(head, 2);
    // pushback(head, 3);
    // pushback(head, 4);
    // display(head);

    // pushback(head, 5);
    // pushback(head, 6);
    // pushback(head, 7);
    // display(head);

    // pushfront(&head, 0);
    // // first=pushfront(first,0);
    // display(head);

    // insert(head, 9, 3);
    // display(head);

    // reverse(&head);
    // display(head);

    // pushback(head, -1);
    // pushback(head, -2);
    // pushback(head, -3);
    // pushback(head, -4);
    // pushfront(&head, 8);
    // pushfront(&head, 9);
    // pushfront(&head, 10);
    // pushfront(&head, 11);
    // pushfront(&head, 12);
    // display(head);
    // reverse(&head);
    // display(head);

    // replace(head, 7, 0);
    // display(head);

    // pop(head,7);
    // display(head);

    // pop_back(head);
    // pop_back(head);
    // pop_back(head);
    // display(head);

    // pop_front(&head);
    // pop_front(&head);
    // pop_front(&head);
    // pop_front(&head);
    // display(head);

    display(head);
    display(second);

    // struct node* merge=merge_sort(head,second);
    struct node *merge = (struct node *)malloc(sizeof(struct node));
    merge = NULL;
    // pushback(&merge, 0);
    // pushback(&merge, 1);
    // pushback(&merge, 2);
    // display(merge);

    merge_sort(head, second);

    return 0;
}