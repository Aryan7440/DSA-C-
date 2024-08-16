#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *ptr = head;
    ListNode *prev = new ListNode(101);

    prev->next = head;
    ListNode *ans = prev;
    while (ptr)
    {
        ListNode *ptr2 = ptr->next;
        int flg = 0;
        while (ptr2 && ptr->val == ptr2->val)
        {
            flg = 1;
            ptr2 = ptr2->next;
        }
        // ptr->next=ptr2;
        if (flg)
        {
            prev->next = ptr2;
            ptr = ptr2;
        }
        else
        {
            prev = ptr;
            ptr = ptr2;
        }
    }
    return ans->next;
}