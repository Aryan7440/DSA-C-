#include <iostream>
using namespace std;
class maxheap
{

    int *arr;
    int maxcap;
    int size;

public:
    maxheap(int s = 10)
    {
        maxcap = s;
        arr = new int[s];
        size = 0;
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
        if (arr[i] > arr[parent(i)])
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
        if (size == maxcap)
        {
            cout << "full" << endl;
            return;
        }

        size++;
        arr[size - 1] = value;
        heapify_up(size - 1);
    }

    int extract_max()
    {
        if (size = 0)
        {
            return INT16_MIN;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
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

    void change_priority(int i, int n)
    {
        arr[i] = n;
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

void heapify(int arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxin = i;
    if (l < n - 1 && arr[maxin] < arr[l])
    {
        maxin = l;
    }
    if (r < n - 1 && arr[maxin] < arr[r])
    {
        maxin = r;
    }
    if (i != maxin)
    {
        swap(arr[i], arr[maxin]);
        heapify(arr, n, maxin);
    }
    // return;
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{

    // maxheap H(10);
    // H.insert(10);
    // H.insert(40);
    // H.insert(24);
    // H.insert(80);
    // H.insert(0);
    // H.insert(30);
    // H.display();

    int arr[]={4,5,67,90,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}