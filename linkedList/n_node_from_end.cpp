// #include<iostream>
#include"linked_list.h"
// using namespace std;
node* nth_node(node* &head,int n)
{
    node* first=head;
    while(n>0)
    {
        first=first->next;
        n--;
    }
    node* nh=new node(0);
    nh->next=head;
    node* sec=nh;
    while(first!=NULL)
    {
        first=first->next;
        sec=sec->next;
    }
    sec->next=sec->next->next;
    return nh->next;
}
int main()
{
    int arr[]={1,2};
    node* head=createlist(arr,sizeof(arr)/4);
    display(head);
    head=nth_node(head,1);
    display(head);
}

