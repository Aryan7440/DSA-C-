#include <iostream>
#include <vector>
using namespace std;

// int floor()
int findPeak(vector<int> &arr)
{
    int start = 0;
    int stop = arr.size() - 1;
    if (stop == 0)
        return arr[stop];
    int mid = (stop - start) / 2;
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid]>arr[mid-1])
            return arr[mid];
        else if (arr[mid] > arr[mid+1])
            stop = mid - 1;
        else
            start = mid + 1;
    }
    return arr[start];
    // return arr[mid];
}

int main()
{
    vector<int> arr = {-3, 96, 63, 57, 12, 3, -4, -44, -55, -66};
    cout<<findPeak(arr);
}
