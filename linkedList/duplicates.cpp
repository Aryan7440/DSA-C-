#include "linked_list.h"

#include <unordered_set>
#include <unordered_map>
// node* reverse(node* head)
// {
//     if(head==NULL || head->next==NULL)return head;
//     node* new_head=reverse(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return new_head;
// }

node *lastAppearance(node *head)
{
    if(head==NULL|| head->next==NULL)return head;
    reverse(head);
    unordered_map <int,int> mp;
    node* ptr=head;
    node* n;
    mp.insert({ptr->data,1});
    while(ptr->next)
    {
//         mp[ptr->data]++;
        n=ptr->next;
        if(mp.count(n->data)==0)
        {
            mp.insert({n->data,1});
            ptr=n;
        }
        else
        {
            node* temp=n;
            ptr->next=n->next;
            delete temp;
        }
        
    }
    reverse(head);
    return head;
    
}

void remove_duplicates(node* head)
{
    while(head!=NULL)
    {
        if(head->next==NULL)return;
        if(head->data==head->next->data)
        {
            head->next=head->next->next;
            continue;
        }
        head=head->next;
    }
}

int main()
{
    int arr[]={4,4,4,7};
    node* a=createlist(arr,sizeof(arr)/4);
    display(a);
    // remove_duplicates(a);
    a=lastAppearance(a);
    display(a);
}