#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    int l = 0, r = arr.size() - 1;
    int mid = l + (r - l) / 2;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] - (mid + 1) > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    int rem = k - (arr[r] - r - 1);
    return arr[r] + rem;
}
int main()
{
    vector<int> arr={2,3,4,7,11};
    cout<<findKthPositive(arr,5);
}