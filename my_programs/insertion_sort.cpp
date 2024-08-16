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
                display(arr, size);     //real time movement
            }
        }
    }
}

int main()
{
    int arr[] = {3, 2, 5, 0, 1, 5};
    int n = sizeof(arr) / 4;
    display(arr, n);
    insertion_sort(arr, n);
    display(arr, n);
}