#include "linked_list.h"

node* reverse_recursion(node * &head)
{
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    node * new_head=reverse_recursion(head->next);
    head->next->next=head;
    head->next=NULL;

    return new_head;
    
}
node *addnumbers(node *a, node *b)
{
    node *ans = new node();
    int carry = 0;
    node *temp = ans;
    reverse(a);
    reverse(b);
    while (a || b || carry)
    {
        int sum = 0;
        if (a != NULL)
        {
            sum = sum + a->data;
            a = a->next;
        }
        if (b != NULL)
        {
            sum = sum + b->data;
            b = b->next;
        }
        sum = sum + carry;
        carry = sum / 10;
        node *res = new node(sum % 10);
        temp->next = res;
        temp = temp->next;
    }
    reverse(ans->next);
    return ans->next;
}


int main()
{
    int arr1[] = {9, 9, 9, 9, 9, 9, 9};
    int arr2[] = {9, 9, 9, 9};
    node *a = createlist(arr1, sizeof(arr1) / 4);
    node *b = createlist(arr1, sizeof(arr2) / 4);
    display(a);
    display(b);
    // addnumbers(a, b);
    node *c = addnumbers(a, b);
    display(c);
}