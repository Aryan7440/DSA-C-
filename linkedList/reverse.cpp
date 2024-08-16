#include <iostream>
using namespace std;
#include "linked_list.h"

// void reverse(node *&head)
// {
//     node *prev = NULL;
//     node *cur = head;
//     node *next = NULL;
//     while (cur != NULL)
//     {
//         next = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = next;
//     }
//     // cur->next = prev;
//     head = prev;
// }
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


node * revereseK(node* &head,int k)
{
    node * prev=NULL;
    node * curr=head;
    node * nextptr;
    int count=0;
    while (curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }

    
    if (nextptr!=NULL)
    {
        head->next=revereseK(nextptr,k);
    }
    return prev;   
}

node* reverse2(node*&head,int l,int r)
{
    node* start=new node(0);
    node* ans=start;
    start->next=head;
    for(int i=1;i<l;i++)
    {
        start=start->next;
    }
    node* cur=start->next;
    node* prev=NULL;
    node* next=NULL;
    for (int i = l; i <= r; i++)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    start->next->next=cur;
    start->next=prev;
    return ans->next;
}



node* UTIL(node* head,int arr[],int i,int n)
{
    if(i==n)return head;
    int count=arr[i];
    node* cur=head;
    node* prev=NULL;
    node* Next=NULL;
    while(cur && count>0)
    {
        Next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=Next;
        count--;
    }
    if(cur)
    {
        head->next=UTIL(Next,arr,i+1,n);
    }
    else return prev;
    return prev;
}

void reverseN_blocks(node* head,int arr[],int n)
{
    head=UTIL(head,arr,0,n);
}


int main()
{
    int arr1[] = {1, 0,2};
    int arr2[] = {5,7,8,2,4};
    node *head = createlist(arr2, sizeof(arr2)/4);
    // node *head2 = createlist(arr2, 7);
    // display(head);
    // push_back(head, 89);
    // reverse(head2);
    // display(head2);
    // reverse(head2);
    // display(head2);

    display(head);
    // node* h3=reverse2(head,2,4);
    // display(h3);
    // reverse(head);
    // head=revereseK(head,2);
    // head=revereseK(head,3);
    // display(head);

    // head=revereseK(head,3);
    reverseN_blocks(head,arr1,sizeof(arr1)/4);
    display(head);

    
}