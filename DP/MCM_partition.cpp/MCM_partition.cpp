#include <bits/stdc++.h>
using namespace std;
int MCM(int N, int arr[], int l, int r, vector<vector<int>> &dp)
{
    if (l + 1 == r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    int res = INT_MAX;
    for (int i = l + 1; i < r; i++)
    {
        res = min(res, arr[l] * arr[r] * arr[i] + MCM(N, arr, l, i, dp) + MCM(N, arr, i, r, dp));
    }
    return dp[l][r] = res;
}
int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return MCM(N, arr, 0, N - 1, dp);
}
// int matrixMultiplication(int N, int arr[])
// {
//     // code here
//     vector<vector<int>> dp(N, vector<int>(N, 0));
//     // return util(N,arr,1,N-1,dp);
//     for (int i = N - 1; i >= 1; i--)
//     {
//         for (int j = 1; j <= N - 1; j++)
//         {
//             if (i == j)
//                 continue;
//             int ans = INT_MAX;
//             for (int k = i; k < j; k++)
//             {
//                 ans = min(ans, arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
//             }
//             dp[i][j] = ans;
//         }
//     }
//     return dp[1][N - 1];
// }
int main()
{
    int arr[]={40,20,30,10,30};
    cout<<matrixMultiplication(sizeof(arr)/sizeof(arr[0]),arr);
}