#include <bits/stdc++.h>
using namespace std;
void max_heapify(vector<int> &arr, int n, int i)
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
        max_heapify(arr, n, maxin);
    }
    return;
}

void create_max_heap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }
}
int extract_max(vector<int> &arr)
{
    int max = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    max_heapify(arr, arr.size(),0);

    return max;
}

void heapify(vector<int> &arr, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int min_in = i;
    if (l < n && arr[min_in] > arr[l])
    {
        min_in = l;
    }
    if (r < n && arr[min_in] > arr[r])
    {
        min_in = r;
    }
    if (i != min_in)
    {
        swap(arr[i], arr[min_in]);
        heapify(arr, min_in, n);
    }
    return;
}

void create_min_heap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

void heapsort(vector<int> &arr)
{
    int n = arr.size();
    create_min_heap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
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
        if (i >= arr.size())
            flag = 0;
        i = i + pow(2, count);
    }
}
void print_min(vector<int> arr)
{
    cout << "min element is: " << arr[0] << endl;
}
int extract_min(vector<int> &arr)
{
    int min = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    heapify(arr, 0, arr.size());

    return min;
}

int main()
{
    // vector<int> arr = {24, 9, 80, 30, 40, 80, 0};
    int n;
    cout << "enter NUMBER of elements:";
    cin >> n;
    vector<int> arr(n);
    cout << "enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> input_arr=arr;    //creating a copy
    display(arr);
    heapsort(arr);
    cout << "heap sort using min heap(descending order): ";
    display(arr);

    create_min_heap(arr, arr.size());
    display(arr);
    print_min(arr);
    display_levels(arr);
    extract_min(arr);
    cout << "after removing minimun elemet:" << endl;
    display_levels(arr);

    cout<<"for max heap: "<<endl;

    cout<<"original:";
    display(input_arr);
    create_max_heap(input_arr,arr.size());
    display_levels(input_arr);
    cout<<"max_elemetn is :"<<extract_max(input_arr)<<endl;
    cout<<"after removing max: ";
    display_levels(input_arr);

}