#include <bits/stdc++.h>
using namespace std;

bool isvalid(vector<int> arr, int std, int pages)
{
    int count = 1;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum > pages)
        {
            sum = arr[i];
            count++;
            if (count > std)
                return true;
        }
    }
    return false;
}
int allocate(vector<int> &arr, int k)
{
    int start = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        start = max(start, arr[i]);
    }
    int stop = 1000;
    int mid = start + (stop - start) / 2;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (isvalid(arr, k, mid))
        {
            start = mid + 1;
        }
        else
        {
            stop = mid - 1;
        }
    }
    return start;
}
int main()
{
    vector<int> v = {13 ,31, 37, 45, 46, 54, 55, 63, 73, 84, 85};
    cout << allocate(v, 9);
}