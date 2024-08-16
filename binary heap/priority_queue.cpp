#include <iostream>
using namespace std;

class priority_queue
{
    int *arr;
    int capacity;
    int size;

public:
    priority_queue(int cap = 100)
    {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void heapify_up(int i)
    {
        while (i > 0)
        {
            if (arr[i] > arr[parent(i)])
            {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
            else
                return;
        }
    }

    void heapify_down(int i)
    {
        int l = left(i);
        int r = right(i);
        int maxin = i;
        if (l < size - 1 && arr[maxin] < arr[l])
        {
            maxin = l;
        }
        if (r < size - 1 && arr[maxin] < arr[r])
        {
            maxin = r;
        }
        if (i != maxin)
        {
            swap(arr[i], arr[maxin]);
            heapify_down(maxin);
        }
        return;
    }

    void heapify(int i)
    {
        if (arr[i]>arr[parent(i)])
        {
            heapify_up(i);
        }
        else
        {
            heapify_down(i);
        }
        return;
        
    }
    void insert(int value)
    {
        size++;
        arr[size - 1] = value;
        heapify_up(size - 1);
    }

    int extract_max()
    {
        int max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify_down(0);
        return max;
    }

    int getmax()
    {
        return arr[0];
    }

    void change_priority(int i,int n)
    {
        arr[i]=n;
        heapify(i);
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    priority_queue p;
    p.insert(56);
    p.insert(89);
    p.insert(6);
    p.insert(87);
    p.insert(13);
    p.insert(34);
    p.insert(39);
    p.display();
    // cout<<"AFTER CHANGING PRIORITY(4th,100):"<<endl;
    // p.change_priority(4,100);
    // p.display();
    // cout<<"MAX EXTRACTION";
    // cout << p.extract_max() << endl;
    // p.display();
    // cout<<"MAX ELEMENT";
    // cout<<p.getmax()<<endl;
    p.heapify_down(0);
    p.display();
    
}