#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int binary_search(int arr[], int l, int r, int n)
{
    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (arr[mid] == n)
        {
            return 1;
        }
        if (arr[mid] > n)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return 1;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {444, 8465, 6, 7, 325, 8,98,54,75,36};
    insertion_sort(arr, sizeof(arr) / 4);
    (binary_search(arr, 0, 5, 69)==-1) ? cout<<"NOT FOUND" : cout<< "FOUND"; 
}