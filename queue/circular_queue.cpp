#include <iostream>
#include "linked_list.h"
using namespace std;

class Cqueue
{
public:
    int size;
    int front;
    int rear;
    int arr[];
    Cqueue(int s = 100)
    {
        size = s;
        front = rear = -1;
        arr[s];
    }
    void enqueue(int x)
    {
        if ((rear == size - 1 && front == 0) || rear == (front - 1) % size)
        {
            cout << "full" << endl;
        }

        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
            return;
        }

        arr[(rear + 1) % size] = x;
        rear++;
    }
    int dequeue()
    {

        if (front == -1)
        {
            printf("empty\n");
            return INT8_MIN;
        }
        int a = arr[front];
        if (front == rear)
        {

            front = rear = -1;
            return a;
        }
        front = (front + 1) % size;
        return a;
    }

    void display()
    {
        int i = front;
        if (front==-1)
        {
            cout<<"empty"<<endl;
            return;
        }
        
        if (i == rear)
        {
            cout << arr[i] << endl;
            return;
        }

        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[i] << endl;
    }
};

int main()
{
    Cqueue cq(4);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.display();
    cq.dequeue();
    cq.display();
    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;
    cout<<cq.dequeue()<<endl;
    cq.display();
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.display();
    cq.enqueue(21);
}