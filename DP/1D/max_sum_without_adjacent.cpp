#include <bits/stdc++.h>
using namespace std;
int util(int *arr, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int i = util(arr,n-2,dp)+arr[n];
    int j = util(arr,n-1,dp);
    
    return dp[n] = max(i, j);
}
// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n)
{
    // code here
    // vector<int> dp(n+1,-1);
    // return util(arr, n - 1, dp);

    int prev=0;
    int next=0;
    for(int i=0;i<n;i++)
    {
        int temp=prev;
        prev=next;
        next=max(temp+arr[i],next);
    }
    return next;
}
int main()
{
    int arr[]={5,5,10,100,10,5};
    cout<<findMaxSum(arr,6);
}