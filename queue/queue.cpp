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

    void deque()
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

int main()
{
    int array1[] = {13, 35, 89, 3, 6, 986, 56};
    queue Q(10);
    cout << Q.empty() << endl;
    Q.enqueue(100);
    cout << Q.empty() << endl;
    cout << Q.peek() << endl;
    Q.deque();
    cout << Q.empty() << endl;
    cout << Q.peek() << endl;
    create(array1, sizeof(array1) / 4, Q);
    Q.display();

    int arr[3] = {1, 2, 3};
    queue q(3);
    create(arr, 3, q);
    q.display();
    q.deque();
    q.display();
    q.deque();
    q.display();
    q.deque();
    q.display();
    cout << q.first << q.last << endl;
    q.enqueue(4);
    cout << q.first << q.last << endl;
    q.enqueue(5);
    cout << q.first << q.last << endl;
    q.enqueue(6);
    cout << q.first << q.last << endl;
}