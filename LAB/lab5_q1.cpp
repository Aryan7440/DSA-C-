// 1>) write a prog to implement heap sort which performs the following operations
//  a) takes int to be sorted as input from yhe user
//  B) performs heap sort over the int
//  c) traverse the heap elements in level wise order
//  d) print the level number and corresponding elemt present at diff leveles of heap consider top level as 0

// 2.) suppose u have been given an array of n int elements the ele ments of the array should be in neg and pos comb your task is to write a prog to find the largest sum of subarray
//  adalab

#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxin = i;
    if (l < n && arr[maxin] < arr[l])
    {
        maxin = l;
    }
    if (r < n && arr[maxin] < arr[r])
    {
        maxin = r;
    }
    if (i != maxin)
    {
        swap(arr[i], arr[maxin]);
        heapify(arr, n, maxin);
    }
    return;
}

void create_heap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapsort(vector<int> &arr, int n)
{
    // create_heap(arr,n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void display(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void display_levels(vector<int> arr)
{
    int flag = 1;
    int i = 1, k, m = 0, count = 0;
    cout << "LEVEL ORDER TRAVERSAL IS: " << endl;
    while (flag)
    {
        cout << "level: " << count << "--";
        for (k = m; k < i && k < arr.size(); k++)
        {
            cout << arr[k] << " ";
        }
        cout << endl;
        m = k;
        count++;
        if (i > arr.size())
            flag = 0;
        i = i + pow(2, count);
    }
}

int main()
{
    vector<int> arr = {7,5,3,6,9,1};
    // int n;
    // cout << "enter NUMBER of elements:";
    // cin >> n;
    // vector<int> arr(n);
    // cout << "enter elements: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << endl;
    int size = arr.size();
    cout << " INITIAL ARRAY:";
    display(arr, size);
    create_heap(arr,size);

    display(arr, size);
    display_levels(arr);

    heapsort(arr, size);
    cout << "AFTER SORTING:";
    display(arr, size);
}