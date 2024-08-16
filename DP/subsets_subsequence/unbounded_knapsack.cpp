#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp, int ind, int W)
{
    if (ind == 0)
    {
        if (W >= weight[ind])
            return (W / weight[ind]) * profit[ind];
        else
            return INT_MIN;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int take = INT_MIN;
    if (W >= weight[ind])
        take = profit[ind] + util(profit, weight, dp, ind, W - weight[ind]);
    int not_take = util(profit, weight, dp, ind - 1, W);
    return dp[ind][W] = max(take, not_take);
}

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
// {
//     // Write Your Code Here.
//     vector<vector<int>>dp(n,vector<int>(w+1,-1));
//     // return util(profit,weight,dp,n-1,w);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<=w;j++)
//         {
//             if(i==0)
//             {
//                 dp[i][j]=(j/weight[0])*profit[0];
//             }
//             else
//             {
//                 int take=0;
//                 if(j>=weight[i])take=profit[i]+dp[i][j-weight[i]];
//                 int not_take=dp[i-1][j];
//                 dp[i][j]=max(take,not_take);
//             }
//         }
//     }
//     return dp[n-1][w];
// }
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> dp(w + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0)
            {
                dp[j] = (j / weight[0]) * profit[0];
            }
            else
            {
                int take = 0;
                if (j >= weight[i])
                    take = profit[i] + dp[j - weight[i]];
                int not_take = dp[j];
                dp[j] = max(take, not_take);
            }
        }
    }
    return dp[w];
}
int main()
{
    vector<int> profit = {5, 11, 13}, weight = {2, 4, 6};
    cout<<unboundedKnapsack(profit.size(),10,profit,weight);
}