#include <bits/stdc++.h>
using namespace std;
int util(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    int n = matrix.size();
    if (i >= n)
        return 0;
    if (j < 0 || j >= n)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int temp = 1e9;
    temp = min(temp, util(matrix, i + 1, j - 1, dp));
    temp = min(temp, util(matrix, i + 1, j, dp));
    temp = min(temp, util(matrix, i + 1, j + 1, dp));
    return dp[i][j] = matrix[i][j] + temp;
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int>dp(n+1,1e9),curr(n+1,1e9);
    for(int i=0;i<n;i++)
    {
        int maxi=1e9;
        for(int j=0;j<n;j++)
        {
            if(i==0)curr[j]=matrix[i][j];
            else
            {
                int a=(j == 0) ? 1e9 : dp[j - 1];
                int b = dp[j];
                int c = (j == n - 1) ? 1e9 : dp[j + 1];
                curr[j]=min(a,min(b,c))+matrix[i][j];
            }
            maxi=min(maxi,curr[j]);
        }
        curr[n]=maxi;
        dp=curr;
    }
    return dp[n];
}
// int minFallingPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     // int ans = 1e9;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     ans = min(ans, util(matrix, 0, i, dp));
//     // }
//     // return ans;
//     for (int i = 0; i < n; i++)
//     {
//         int maxi = INT_MAX;
//         for (int j = 0; j < n; j++)
//         {
//             if (i == 0)
//                 dp[i][j] = matrix[i][j];
//             else
//             {
//                 int a = (j == 0) ? 1e9 : dp[i - 1][j - 1];
//                 int b = dp[i - 1][j];
//                 int c = (j == n - 1) ? 1e9 : dp[i - 1][j + 1];
//                 dp[i][j] = min(a, min(b, c))+matrix[i][j];
//             }
//             maxi = min(maxi, dp[i][j]);
//         }
//         dp[i][n] = maxi;
//     }
//     return dp[n-1][n];
// }
int main()
{
    vector<vector<int>> matrix={{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(matrix);
}