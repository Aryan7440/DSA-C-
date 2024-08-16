#include <iostream>
#include "linked_list.h"
using namespace std;

bool detect_loop(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && slow != NULL && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void create_loop(node *head, int pos)
{
    while (pos > 0)
    {
        head = head->next;
        pos--;
    }
    node *temp = head;
    while (head->next)
    {
        head = head->next;
    }
    head->next = temp;
}

void removeLoop(node *head)
{
    if (!detect_loop)
    {
        return;
    }

    if (head == NULL || head->next == NULL)
        return;

    node *fast = head;
    node *slow = head;

    slow = slow->next;
    fast = fast->next->next; // beacuse fast and slow are same at the beginning

    while (fast && slow != fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow == fast)
    {
        // slow=head;
        fast = head;
        while (fast->next != slow->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = NULL;
        // if (slow == fast)
        //     while (fast->next != slow)
        //         fast = fast->next;
        // else {
        //     while (slow->next != fast->next) {
        //         slow = slow->next;
        //         fast = fast->next;
        //     }
        // }
        // fast->next=NULL;
    }
    else
        return;
}

// void remove_dup(node *head)
// {
//     node *t = head;
//     while (t != NULL)
//     {
//         node *t2 = t->next;
//         node *ch = head;
//         while ((ch->next) != t2)
//         {
//             if (ch->next->data==t2->data)
//             {
//                 ch->next=ch->next->next;
//             }
//         }
//         t=t->next;
//     }
//     display(head);

// }
void Reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void removedup(node *head)
{
    reverse(head);
    node *temp = head;
    node *temp2;

    while (temp != NULL)
    {
        temp2 = temp;
        while (temp2->next != NULL)
        {
            if (temp->data == temp2->next->data)
            {
                temp2->next = temp2->next->next;
            }
            else
                temp2 = temp2->next;
        }
        // display(head);
        temp = temp->next;
    }
    reverse(head);
    display(head);
}

void rd(node* head)
{
    node* ans=new node(-1);
    ans->next=head;
    node* t1=ans;
    node* t2;
    while(t1->next!=NULL)
    {
        t2=t1->next->next;
        while (t2!=NULL)
        {
            if(t1->next->data==t2->data)
            {
                t1->next=t1->next->next;
                break;
            }
             t2=t2->next;
        }
        // t1=t1->next;
        if (t2==NULL)
        {
            t1=t1->next;
        }
        
        
    }
    display(ans->next);
}
node *lastAppearance(node *head)
{
    //  Make a dummy node for corner cases.
    node *dummy = new node(-1);
    dummy->next = head;

    //  Now start curr with dummy node.
    node *curr = dummy, *temp;

    //  Iterate over list.
    while (curr->next != NULL)
    {
        //  Check weather the data of curr->next is already exist in the list or not.
        temp = curr->next->next;
        while (temp != NULL)
        {
            if (curr->next->data == temp->data)
            {
                //  If exist then delete the curr node.
                node *duplicatNode = curr->next;
                curr->next = curr->next->next;

                delete duplicatNode;
                break;
            }
            temp = temp->next;
        }

        //  That's means we couldn't find the duplicate data for the data of curr->next.
        if (temp == NULL)
        {
            curr = curr->next;
        }
    }
    
    //  Return the modified data.
    return dummy->next;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 5, 11, 13, 87, 3, 15, 18, 87};
    node *loop = createlist(arr, sizeof(arr) / 4);
    display(loop);
    // Reverse(loop);
    // display(loop);
    // cout << detect_loop(loop) << endl;
    // create_loop(loop, 3);
    // cout << detect_loop(loop) << endl;
    // display(loop);
    // removeLoop(loop);
    // display(loop);
    // cout << detect_loop(loop) << endl;
    // removedup(loop);
    rd(loop);
    // loop=lastAppearance(loop);
    // display(loop);
}