#include <bits/stdc++.h>
using namespace std;
int util(int m, int n, int i, int j, vector<vector<int>> &dp)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i < m && j < n)
    {
        int r = util(m, n, i, j + 1, dp);
        int d = util(m, n, i + 1, j, dp);
        return dp[i][j] = r + d;
    }
    return 0;
}
// int uniquePaths(int m, int n)
// {
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//     // dp[m-1][n-1]=1;
//     // return util(m,n,0,0,dp);
//     // dp[0][0]=1;
//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             if (i == 0 || j == 0)
//                 dp[i][j] = 1;
//             else
//                 dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//         }
//     }
//     return dp[m - 1][n - 1];
// }
int uniquePaths(int m,int n)
{
    vector<int> dp(n+1,1);
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp[n-1];
}
int main()
{
    cout << uniquePaths(3, 7);
}