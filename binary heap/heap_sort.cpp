#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxin = i;
    if (l < n  && arr[maxin] < arr[l])
    {
        maxin = l;
    }
    if (r < n  && arr[maxin] < arr[r])
    {
        maxin = r;
    }
    if (i != maxin)
    {
        swap(arr[i], arr[maxin]);
        // i++;
        // heapify(arr, n, i);
        heapify(arr, n, maxin);
    }
    return;
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

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 67, 90, 8,45,78,1,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<" INITIAL ARRAY:";
    display(arr,size);
    heapsort(arr, size);
    cout<<"AFTER SORTING:";
    display(arr,size);
    // heapify(arr,size,0);
    // display(arr,size);
}