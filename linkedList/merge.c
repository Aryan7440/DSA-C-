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
    ptr->next = NULL;

    if (*head == NULL)
    {
        *head = ptr;
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

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *merge_sort(struct node *a, struct node *b)
{
    struct node *ans = (struct node *)malloc(sizeof(struct node));
    ans = NULL;
    while (a != NULL && b != NULL)
    {

        if ((a->data >= b->data))
        {
            pushback(&ans, b->data);
            b = b->next;
        }
        if ((b->data > a->data))
        {
            pushback(&ans, a->data);
            a = a->next;
        }
    }
    while (b != NULL)
    {
        pushback(&ans, b->data);
        b = b->next;
    }
    while (a != NULL)
    {
        pushback(&ans, a->data);
        a = a->next;
    }
    return ans;
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
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
    pushback(&head, 19);

    second->data = -1;
    second->next = NULL;
    pushback(&second, 2);
    pushback(&second, 5);
    pushback(&second, 9);
    pushback(&second, 14);
    pushback(&second, 15);
    pushback(&second, 16);
    pushback(&second, 17);
    pushback(&second, 18);
    pushback(&second, 19);
    pushback(&second, 20);

    display(head);
    display(second);

    struct node *merge = (struct node *)malloc(sizeof(struct node));

    merge = merge_sort(head, second);
    display(merge);

    return 0;
}