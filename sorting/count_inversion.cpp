#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    vector<int> ans(r - l + 1);
    int inv = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            ans[k] = arr[i];
            i++;
        }
        else
        {
            ans[k] = arr[j];
            j++;
            inv = inv + (mid + 1 - i);
        }
        k++;
    }
    while (i <= mid)
    {
        ans[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        ans[k] = arr[j];
        j++;
        k++;
    }
    for (int o = l, p = 0; o <= r; o++, p++)
    {
        arr[o] = ans[p];
    }

    return inv;
}

int divide(vector<int> &arr, int l, int r)
{
    int inv = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        inv += divide(arr, l, mid);
        inv += divide(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}
int mergesort(vector<int> &arr)
{
    return divide(arr, 0, arr.size() - 1);
}
int main()
{
    // vector<int> arr = {8, 5, 3, 1,4};
    vector<int> arr = {1, 20, 6, 4, 5, 5, 2, 5};

    cout << mergesort(arr) << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
