#include <bits/stdc++.h>
using namespace std;

int sumS(vector<int> arr, int S)
{
    int i = 0, j = 0;
    int count = INT_MAX;
    int sum = 0;
    int n = arr.size();
    while (j < n)
    {
        if (sum < S)
        {
            j++;
            sum += arr[j];
        }
        else if (sum >= S)
        {
            count = min(j - i + 1, count);
            if (sum == S)
            {
                i = j + 1;
                j=i;
            }
            else
            {
                i = j;
            }
            sum = arr[i];
        }
    }

    return (count==INT_MAX)?0:count;
}

int main()
{
    vector<int> arr = {2,3,1,2,4,3};
    cout << sumS(arr, 7);
}