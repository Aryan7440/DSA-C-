#include <bits/stdc++.h>
using namespace std;
int util(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (W >= wt[n])
            return val[0];
        else
            return 0;
    }
    if (dp[n][W] != -1)
        return dp[n][W];
    int take = INT_MIN;
    if (W >= wt[n])
        take = val[n] + util(W - wt[n], wt, val, n - 1, dp);
    int not_take = util(W, wt, val, n - 1, dp);
    return dp[n][W] = max(take, not_take);
}
// Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0)
            {
                if (j >= wt[i])
                    curr[j] = val[i];
                else
                    curr[j] = 0;
            }
            else
            {
                int take = (j - wt[i] >= 0) ? val[i] + prev[j - wt[i]] : INT_MIN;
                int not_take = prev[j];
                curr[j] = max(take, not_take);
            }
            prev=curr;
        }
    }
    return prev[W];
}
// int knapSack(int W, int wt[], int val[], int n)
// {
//     // Your code here
//     vector<vector<int>> dp(n, vector<int>(W + 1, 0));
//     //   return util(W,wt,val,n-1,dp);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < W + 1; j++)
//         {
//             if (i == 0)
//             {
//                 if (j >= wt[i])
//                     dp[i][j] = val[i];
//                 else
//                     dp[i][j] = 0;
//             }
//             else
//             {
//                 int take = (j - wt[i] >= 0) ? val[i] + dp[i - 1][j - wt[i]] : INT_MIN;
//                 int not_take = dp[i - 1][j];
//                 dp[i][j] = max(take, not_take);
//             }
//         }
//     }
//     return dp[n - 1][W];
// }
int main()
{
    vector<int>v={186, 186, 186, 419, 419, 419, 419, 419, 83, 83, 83, 83, 408, 408, 408, 408, 408, 408, 408, 408};
    cout<<accumulate(v.begin(),v.end(),0);
}
