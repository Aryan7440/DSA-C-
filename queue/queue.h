#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value = 0)
    {
        data = value;
        next = NULL;
    }
};

class queue
{
public:
    node *front;
    node *rear;
    queue()
    {
        front = rear = NULL;
    }
    void enqueue(int x)
    {
        node *new_node = new node(x);
        if (front == NULL)
        {
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear = new_node;
    }
    void deque()
    {
        if (front == NULL)
        {
            cout << "empty" << endl;
            return;
        }

        node *deq = front;
        front = front->next;
        delete deq;
        if (front == NULL)
        {
            rear == NULL;
        }
    }
    int top()
    {
        if (front == NULL)
        {
            return -1;
        }

        return front->data;
    }
    bool empty()
    {
        return (front == NULL);
    }
};