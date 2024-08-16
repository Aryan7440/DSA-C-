#include <bits/stdc++.h>
using namespace std;
long long putMarbles(vector<int> &weights, int k)
{
    int n = weights.size();
    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = weights[i] + weights[i + 1];
    }
    sort(arr.begin(), arr.end());
    long long MAX = 0;
    long long MIN = 0;
    for (int i = 0;i<n-1 && i < k; i++)
    {
        MAX += arr[n - 2 - i];
        MIN += arr[i];
    }
    return MAX - MIN;
}
int main()
{
    vector<int> weights = {1,3};
    int k = 2;
    cout<<putMarbles(weights,k);
}