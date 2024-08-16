#include <iostream>
#include "linked_list.h"
using namespace std;

class queue
{
    public:
    node* front;
    node* rear;
    queue()
    {
        front=rear=NULL;
    }
    void enqueue(int x)
    {
        node* new_node=new node(x);
        if (front==NULL)
        {
            front=rear=new_node;
            return;
        }
        rear->next=new_node;
        rear=new_node;
    }
    void deque()
    {
        if (front==NULL)
        {
            cout<<"empty"<<endl;
            return ;
        }
        
        node* deq=front;
        front=front->next;
        delete deq;
        if (front==NULL)
        {
            rear==NULL;
        }
        
    }
    int top()
    {
        if (front==NULL)
        {
            return -1;
        }
        
        return front->data;
    }
    bool empty()
    {
        return (front==NULL);
    }

};



int main()
{
    queue q;
    cout<<q.empty()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    display(q.front);
    q.deque();
    q.deque();
    q.deque();
    display(q.front);
    cout<<q.top()<<endl;
    cout<<q.empty()<<endl;

}