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
        arr = new int[100];
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
};

class queue
{
    int *arr;
    int first;
    int last;
    int size;

public:
    queue(int s)
    {
        size = s;
        arr = new int[s];
        first = -1;
        last = -1;
    }

    void enqueue(int x)
    {
        if (last == size - 1)
        {
            cout << "full queue" << endl;
            return;
        }
        if (first == -1)
        {
            first++;
        }
        last++;
        arr[last] = x;
    }

    void deque()
    {
        if (first > last || first == -1)
        {
            cout << "full" << endl;
            return;
        }
        first++;
    }
    int peek()
    {
        return arr[first];
    }

    void display()
    {
        for (int i = first; i <= last; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool empty()
    {
        if (first == -1 || first > last)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

class queue_using_stack
{
    Stack s1, s2;

public:
    void enq(int x)
    {
        if (s1.empty())
        {
            s1.push(x);
            return;
        }
        // s2.push(x);
        while (!s1.empty())
        {
            s2.push(s1.peek());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.peek());
            s2.pop();
        }
    }

    void deq()
    {
        if (s1.empty())
        {
            cout << "empty" << endl;
            return;
        }

        s1.pop();
    }

    int top()
    {
        return s1.peek();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    queue_using_stack a;
    a.enq(1);
    a.enq(2);
    a.enq(3);
    a.enq(4);
    a.enq(5);
    a.enq(6);

    cout << a.top() << endl;
    cout << a.empty() << endl;
    a.deq();
    cout << a.top() << endl;
    a.deq();
    cout << a.top() << endl;
    a.deq();
    cout << a.top() << endl;
    a.deq();
    cout << a.top() << endl;
    a.deq();
    cout << a.top() << endl;
    a.deq();
    cout << a.empty() << endl;
    // cout<<a.top()<<endl;
}