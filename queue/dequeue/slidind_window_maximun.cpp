#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    Node *prev;
    int val;
    Node(int v = 0)
    {
        val = v;
        next = prev = NULL;
    }
};

class dque
{
public:
    Node *front;
    Node *back;
    int size;
    dque()
    {
        front = new Node(INT_MIN);
        back = new Node(INT_MAX);
        front->next = back;
        back->prev = front;
        size=0;
    }

    void push_back(int val)
    {
        Node *temp = new Node(val);
        back->prev->next = temp;
        temp->next = back;
        temp->prev = back->prev;
        back->prev = temp;
        size++;
    }
    int front_()
    {
        return front->next->val;
    }
    int back_()
    {
        return back->prev->val;
    }
    void pop_back()
    {
        Node *temp = back->prev;
        back->prev = back->prev->prev;
        back->prev->next = back;
        delete temp;
        size--;
    }
    void pop_front()
    {
        Node *temp = front->next;
        front->next = front->next->next;
        front->next->prev = front;
        delete temp;
        size--;
    }
};
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    dque *dq = new dque();
    int n = nums.size();
    // int ans = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (i - k >= 0 && dq->front_() < i - k + 1)
            dq->pop_front();
        while (dq->size > 0 && nums[dq->back_()] < nums[i])
            dq->pop_back();
        dq->push_back(i);
        if (i - k + 1 >= 0)
            ans.push_back(nums[dq->front_()]);
    }
    return ans;
}
int main()
{
    // vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> nums = {1,3,1,2,0,5};
    vector<int> ans = maxSlidingWindow(nums, 3);
    for (auto i : ans)
        cout << i << " ";
    // dque *dq=new dque();
    // dq->push_back(1);
    // dq->push_back(2);
    // dq->push_back(3);
    // dq->push_back(4);
}