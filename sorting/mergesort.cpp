#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
    int ans[(end - start) + 1];
    int i = start, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            ans[k] = arr[i];
            i++;
        }
        else
        {
            ans[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        ans[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        ans[k] = arr[j];
        j++;
        k++;
    }
    // arr = ans;
    for (i = start; i <= end; i++)
    {
        arr[i] = ans[i - start];
    }
}

void mergesort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int count_inversions(vector<int> &v, int start, int mid, int stop)
{
    int i = start, j = mid + 1;
    int k = start;
    int count = 0;
    vector<int> ans(v.size());
    while (i <= mid && j <= stop)
    {
        if (v[j] < v[i])
        {
            count = count + (j - mid + 1);
            ans[k] = v[j];
            j++;
        }
        else
        {
            ans[k] = v[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        ans[k] = v[i];
        i++;
        k++;
    }
    while (j <= stop)
    {
        ans[k] = v[j];
        j++;
        k++;
    }
    for (i = start; i <= stop; i++)
    {
        v[i] = ans[i];
    }
    return count;
}

int inversion_count(vector<int> &v, int start, int stop)
{
    // if (start >= stop)
    // {
    //     return 0;
    // }
    int count = 0;
    if (start < stop)
    {
        int mid = start + (stop - start) / 2;
        
        count += inversion_count(v, start, mid);
        count += inversion_count(v, mid + 1, stop);
        count += count_inversions(v, start, mid, stop);
    }
    return count;
}
int main()
{
    // int arr1[] = {8, 5, 3, 1,4};
    vector<int> arr = {8, 5, 3, 1, 4};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    // mergesort(arr1, 0, 4);
    cout << inversion_count(arr, 0, arr.size() - 1) << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
