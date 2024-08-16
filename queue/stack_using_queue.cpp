#include <iostream>
using namespace std;
#include "Q.h"
#include "stack.h"

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

// class queue
// {
//     int *arr;
//     int first;
//     int last;
//     int size;

// public:
//     queue(int s = 100)
//     {
//         size = s;
//         arr = new int[s];
//         first = -1;
//         last = -1;
//     }

//     void enqueue(int x)
//     {
//         if (last == size - 1)
//         {
//             cout << "full queue" << endl;
//             return;
//         }
//         if (first == -1)
//         {
//             first++;
//         }
//         last++;
//         arr[last] = x;
//     }

//     void deque()
//     {
//         if (first > last || first == -1)
//         {
//             cout << "full" << endl;
//             return;
//         }
//         first++;
//     }
//     int peek()
//     {
//         return arr[first];
//     }

//     void display()
//     {
//         for (int i = first; i <= last; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     bool empty()
//     {
//         if (first == -1 || first > last)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// };

class stack_using_queue
{
private:
    queue q1, q2;

public:
    void push(int x)
    {
        if (q1.empty())
        {
            q1.enqueue(x);
            return;
        }
        q2.enqueue(x);
        while (!q1.empty())
        {
            q2.enqueue(q1.peek());
            q1.deque();
        }
        queue temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        q1.deque();
    }

    int peek()
    {
        return q1.peek();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    stack_using_queue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    cout<<a.empty()<<endl;
    cout << a.peek() << endl;
    a.pop();
    cout << a.peek() << endl;
    a.pop();
    cout << a.peek() << endl;
    a.pop();
    cout << a.peek() << endl;
    a.pop();
    cout<<a.empty()<<endl;
    
}
