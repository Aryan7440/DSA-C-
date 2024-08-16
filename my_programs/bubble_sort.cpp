#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // int arr[] = {9, 61, 354, 354, 21484, 1, 6, 35, 4};
    int arr[5]={2,5,4,6,9};
    display(arr, sizeof(arr) / 4);
    bubble_sort(arr, sizeof(arr)/4);
    // cout << arr[0] << " ";
    display(arr, sizeof(arr) / 4);
}


