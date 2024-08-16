#include <bits/stdc++.h>
using namespace std;
int util(int n, vector<int> &dp) // memoisattion
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = util(n - 1, dp) + util(n - 2, dp);
}
int climbStairs(int n)   //constaint space
{
    if(n<2)return n;
    int i=1;
    int j=2;
    int k=2;
    while(k++<n)
    {
        int temp=i;
        i=j;
        j=temp+j;
    }
    return j;
}
// int climbStairs(int n)  //tabular
// {
//     vector<int> dp(n+2);
//     dp[0]=0;
//     dp[1]=1;
//     dp[2]=2;
//     for(int i=3;i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }
// int climbStairs(int n)
// {
//     vector<int> dp(n + 2, -1);
//     dp[0] = 0;
//     dp[1] = 1;
//     dp[2] = 2;
//     return util(n, dp);
// }
int main()
{
    cout << climbStairs(5);
}
