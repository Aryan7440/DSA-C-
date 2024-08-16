#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int count;

public:
    Stack(int size)
    {
        arr = new int[size];
        count = -1;
    }
    Stack()
    {
        arr = new int[10];
        count = -1;
    }

    int peek()
    {
        return arr[count];
    }

    bool empty()
    {
        return !(count + 1);
    }
    void pop()
    {
        count--;
    }
    void push(int x)
    {
        count++;
        arr[count] = x;
    }
    void display()
    {
        for (int i = 0; i <= count; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insert_at_bottom(int x)
    {
        if (empty())
        {
            push(x);
        }
        else
        {
            int temp = peek();
            pop();
            insert_at_bottom(x);
            push(temp);
        }
    }
    void reverse()
    {
        if (!empty())
        {
            int temp = peek();
            pop();
            reverse();
            insert_at_bottom(temp);
        }
    }
};