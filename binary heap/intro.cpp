#include <iostream>
using namespace std;

class minheap // min
{

    int *arr;
    int maxcap;
    int size;

public:
    minheap(int s = 100)
    {
        maxcap = s;
        arr = new int[s];
        size = 0;
    }
    ~minheap()
    {
        delete[] arr;
    }

    void insert(int x)
    {
        if (size == maxcap)
        {
            cout << "full" << endl;
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = x;

        while (i != 0)
        {
            if (arr[i] < arr[(i - 1) / 2])
            {
                swap(arr[i], arr[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            else
                return;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    int extract_min()
    {
        if (size == 0)
        {
            return INT32_MIN;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }

        int min = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return min;
    }

    void heapify(int index)
    {
        // int l = 2 * index + 1;
        // int r = 2 * index + 2;
        // int small_index = index;
        // if (l < size && arr[l] < arr[index])
        // {
        //     small_index = l;
        // }
        // if (r < size && arr[small_index] > arr[r])
        // {
        //     small_index = r;
        // }
        // if (small_index != index)
        // {
        //     swap(arr[index], arr[small_index]);
        //     heapify(small_index);
        // }


        int smallest = (arr[2 * index + 1] > arr[2 * index + 2]) ? (2 * index + 2) : (2 * index + 1);
        if (arr[index]<arr[(index-1)/2])
        {
            heapify_up(index);
            return;
        }
        else if (arr[index]>arr[smallest])
        {
            heapify_down(index);
        }
        
        
    }

    void heapify_up(int index)
    {
        int i = index;
        while (i > 0)
        {
            if (arr[i] < arr[(i - 1) / 2])
            {
                swap(arr[i], arr[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            else
                return;
        }
    }
    void heapify_down(int index)
    {
        int n = size - 1;
        int i = index;
        while (i < n)
        {
            int smallest = (arr[2 * i + 1] > arr[2 * i + 2]) ? (2 * i + 2) : (2 * i + 1);
            if (arr[i] > arr[smallest])
            {
                swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else return;
        }
    }

    void change(int index,int new_value)
    {
        arr[index]=new_value;
        heapify(index);
    }
};

int main()
{
    minheap h(10);
    h.insert(40);
    h.insert(24);
    h.insert(80);
    h.insert(0);
    h.insert(30);
    h.insert(80);
    h.insert(9);
    h.display();

    // cout << h.extract_min() << endl;
    // h.display();
    h.change(2,90);
    h.display();
    // cout << h.extract_min() << endl;
    // h.display();
}