#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &A, int l, int r, int end)
{
    if (l >= r)
        return 0;
    vector<int> ans(end - l + 1);
    int k = 0;
    int i = l;
    int j = r;
    int count = 0;
    while (i < r && j <= end)
    {
        if (A[i] > A[j])
        {
            count += r - i;
            ans[k] = A[j];
            j++;
        }
        else
        {
            ans[k] = A[i];
            i++;
        }
        k++;
    }
    while (i < r)
    {
        ans[k++] = A[i++];
    }
    while (j <= end)
    {
        ans[k++] = A[j++];
    }
    for (i = 0; i < end - l + 1; i++)
    {
        A[l + i] = ans[i];
    }
    return count;
}

int mergesort(vector<int> &A, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    int left = mergesort(A, l, mid);
    int right = mergesort(A, mid + 1, r);
    int ans = merge(A, l, mid + 1, r);
    return ans + left + right;
}

int countInversions(vector<int> &A)
{
    return mergesort(A, 0, A.size() - 1);
}
int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << countInversions(arr) << endl;
    for (auto i : arr)
        cout << i << " ";
    return 0;
}
