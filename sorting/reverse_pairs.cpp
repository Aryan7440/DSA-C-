#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int start, int mid, int end)
{
    int ans[(end - start) + 1];
    int i = start, j = mid + 1;
    int k = 0;
    int count = 0;
    int l=i;
    int r=mid+1;
    while(l<=mid)
    {
        while(l<=mid && arr[l]<=2*arr[r])l++;
        if(l<=mid)count+=mid-l+1;
        r++;
        if(r==end+1)break;
    }
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            ans[k] = arr[i];
            i++;
        }
        else
        {
            // if (arr[i] > 2 * arr[j])
            //     count += (mid - i + 1);
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
    for (i = start; i <= end; i++)
    {
        arr[i] = ans[i - start];
    }
    return count;
}

int mergesort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    int l = mergesort(arr, start, mid);
    int r = mergesort(arr, mid + 1, end);

    int m = merge(arr, start, mid, end);
    return l + r + m;
}
int reversePairs(vector<int> &nums)
{
    return mergesort(nums, 0, nums.size() - 1);
}
int main()
{
    vector<int> nums={1,3,2,3,1};
    cout<<reversePairs(nums);
}