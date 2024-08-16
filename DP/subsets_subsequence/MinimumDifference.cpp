#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 9};
    int n = arr.size();
    int sum = 0;
    // vector<int>prefix(n);
    // for(int i=0;i<n;i++)
    // {
    //     sum+=arr[i];
    //     prefix[i] = sum;
    // }
    // int total = sum;
    vector<int> dp(1000, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1000; j >= arr[i]; j--)
        {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
}