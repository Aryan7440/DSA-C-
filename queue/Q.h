#include <iostream>
using namespace std;
class queue
{
public:
    int *arr;
    int first;
    int last;
    int size;

    queue(int s = 10)
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

    void deque()     //O(n) time
    {

        if (first == -1)
        {
            cout << "empty" << endl;
            return;
        }
        if (last == 0)
        {
            first = last = -1;
            return;
        }

        for (int i = 0; i < last; i++)
        {
            arr[i] = arr[i + 1];
        }
        last--;
    }
    int peek()
    {
        if (first > last || first == -1)
        {
            // cout << "full" << endl;
            // return ;
        }
        return arr[first];
    }

    void display()
    {
        if (first == -1)
        {
            cout << "empty" << endl;
            return;
        }

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

void create(int arr[], int size, queue &q)
{
    for (int i = 0; i < size; i++)
    {
        q.enqueue(arr[i]);
    }
}