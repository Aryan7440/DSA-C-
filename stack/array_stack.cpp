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
void insert_end(Stack &s, int x)
{
    if (s.empty())
    {
        s.push(x);
    }
    else
    {
        int ele = s.peek();
        s.pop();
        insert_end(s, x);
        s.push(ele);
    }
}

void rev(Stack &s)
{
    if (!s.empty())
    {
        int element = s.peek();
        s.pop();
        rev(s);
        insert_end(s, element);
    }

    // return s;
}

int main()
{
    Stack a;
    a.push(0);
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(3);
    a.push(33);
    a.push(12);
    a.pop();
    a.display();
    // cout<<a.count;
    rev(a);
    // cout<<a.peek()<<endl;
    // a.pop();
    // cout<<a.peek()<<endl;
    a.display();
    a.reverse();
    a.display();
    // a.peek();
}