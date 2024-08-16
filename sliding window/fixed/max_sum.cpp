#include <iostream>
#include <vector>
using namespace std;

int max_sum(vector<int> arr, int n, int k)
{
    int i = 0, j = 0, sum = 0;
    int maxsum = 0;
    while ((j) < k)
    {
        sum += arr[j];
        j++;
    }
    // i++;
    maxsum = sum;
    while (j < n)
    {
        sum = sum + arr[j] - arr[i];
        maxsum = max(maxsum, sum);
        i++;
        j++;
    }
    return maxsum;
}

int main()
{
    vector<int> a = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    cout<<max_sum(a,sizeof(a)/4,4);
}