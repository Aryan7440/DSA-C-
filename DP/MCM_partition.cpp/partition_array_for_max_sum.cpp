#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &arr, int i, int j)
{
    int ans = INT_MIN;
    for (int k = i; k <= j; k++)
        ans = max(ans, arr[k]);
    return ans;
}
int util(vector<int> &arr, int k, int i, vector<int> &dp)
{
    if (i >= arr.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MIN;
    for (int l = i; l < i + k && l < arr.size(); l++)
    {
        ans = max(ans, ((l - i + 1) * find(arr, i, l)) + util(arr, k, l + 1, dp));
    }
    return dp[i] = ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    // return util(arr,k,0,dp);
    for (int i = n - 1; i >= 0; i--)
    {
        int ans = INT_MIN;
        for (int l = i; l < i + k && l < arr.size(); l++)
        {
            ans = max(ans, ((l - i + 1) * find(arr, i, l)) + dp[l + 1]);
        }
        dp[i] = ans;
    }
    return dp[0];
}
int main()
{
    vector<int>arr={1,15,7,9,2,5,10};
    int k=3;
    cout<<maxSumAfterPartitioning(arr,k);//{15,15,15,9,10,10,10}=84
}