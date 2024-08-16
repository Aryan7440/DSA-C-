#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int> &arr)
{
    int start = 0;
    int stop = arr.size() - 1;
    int mid = (stop - start) / 2;
    int diff=(arr[stop]-arr[start])/(stop+1);
    while (start <= stop)
    {
        mid = start + (stop - start) / 2;
        if((arr[mid]-arr[0])/diff==mid)start=mid+1;
        else stop=mid-1;
    }
    return arr[stop]+diff;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,7,8,9};
    cout<<findPeak(arr);
}
