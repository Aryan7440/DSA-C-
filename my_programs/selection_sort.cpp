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

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i], index = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
        // display(arr, n);          //for seeing every step
    }
}

int main()
{
    int arr[] = {3, 2, 5, 0, 12, 654, 987, 6, 5, 7, 89, 5};
    int n = sizeof(arr) / 4;
    display(arr, n);
    selection_sort(arr, n);
    // display(arr, n);
}