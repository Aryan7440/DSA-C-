#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x = 0)
    {
        data = x;
        next = NULL;
    }
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
node *createlist(int arr[], int n)
{
    node *head = new node(arr[0]);
    for (int i = 1; i < n; i++)
    {
        push_back(head, arr[i]);
    }
    return head;
}
// node *middle(node *head)
// {
//     node *fast = head->next;
//     node *slow = head;
//     while (slow->next && fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return slow;
// }
node *merge(node *head1, node *head2)
{

    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
    node *res = NULL;
    if (head1->data >= head2->data)
    {
        res = head2;
        res->next = merge(head1, head2->next);
    }
    else
    {
        res = head1;
        res->next = merge(head1->next, head2);
    }
    return res;
}

void split(node *&head, node *&h1, node *&h2)
{

    if (head == NULL || head->next == NULL)
    {
        h1 = head;
        h2 = NULL;
        return;
    }
    node *fast = head->next;
    node *slow = head;
    while (slow->next && fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // node* mid=slow;

    h1 = head;
    h2 = slow->next;
    slow->next = NULL;
}
node *merge_sort(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *head1;
    // node *mid = middle(head);
    node *head2;
    // mid->next = NULL;
    split(head, head1, head2);
    head1=merge_sort(head1);
    head2=merge_sort(head2);
    node* ans = merge(head1, head2);
    return ans;
}

int main()
{
    int arr[] = {4, 7, 2, 9, 7, 0, 1, 3};
    // int arr2[] = {2, 4, 4, 7};
    node *a = createlist(arr, sizeof(arr) / 4);
    // node *b = createlist(arr2, sizeof(arr) / 4);
    display(a);
    // display(b);
    // display(middle(a));
    // node *c = merge(a, b);
    node *c = merge_sort(a);
    display(c);

    // node*h1;
    // node*h2;
    // split(a,h1,h2);
    // display(h1);
    // display(h2);

    // int a1[] = {1, 3, 5, 7};
    // int a2[] = {2, 4, 6, 8, 9};
    // node *p = createlist(a1, sizeof(a1) / 4);
    // node *q = createlist(a2, sizeof(a2) / 4);
    // display(p);
    // display(q);
    // node* ans=merge(p,q);
    //  display(ans);
   
}