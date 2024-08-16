#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int i = 0, j = 0, count = 1;
    int mc = 1;
    while (j < n)
    {
        j++;
        if (arr[j] == arr[j - 1] + 1)
            count++;
        else if (arr[j] == arr[j - 1])
        {
            j++;
        }
        else
        {
            mc = max(mc, count);
            count = 1;
            i = j;
            //             j++;
        }
    }
    return mc;
}

int main()
{
    vector<int> arr={1,1,2,3,4};
    // arr.cl
    cout<<lengthOfLongestConsecutiveSequence(arr,arr.size());
}