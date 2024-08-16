#include <bits/stdc++.h>
#include "linked_list.h"

void swap_node(node *&head)
{
    node *new_head = head->next;
    head->next = head->next->next;
    new_head->next = head;
}

void insertion_sort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1;
        while (arr[j] > arr[j + 1] && j >= 0)
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

void dis_arr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
node *sort(node *&head)
{
    node *dummy = new node(INT_MIN);
    dummy->next = head;
    node *curr = head;
    node *prev = dummy;
    while (curr)
    {
        if (curr->next && curr->next->data < curr->data)
        {
            while (prev->next && prev->next->data < curr->next->data)
            {
                prev = prev->next;
            }
            node *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
            prev=dummy;
        }
        else
        {
            curr = curr->next;
        }
    }
    return dummy->next;
}

int main()
{
    vector<int> arr = {-1, 5, 3, 4, 0};
    node *head = createlist(arr);
    display(head);
    node *h = sort(head);
    display(h);

    // dis_arr(arr);
    // insertion_sort(arr);
    // dis_arr(arr);
    // insertion_sort(arr);
}