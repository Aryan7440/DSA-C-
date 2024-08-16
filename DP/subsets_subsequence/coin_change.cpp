#include <bits/stdc++.h>
using namespace std;

int util(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9;
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int take = INT_MAX ;
    if (amount >= coins[ind])
    {
        take = 1 + util(coins, amount - coins[ind], ind, dp);
    }
    int not_take = util(coins, amount, ind - 1, dp);
    return dp[ind][amount] = min(take, not_take);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int>dp(amount+1,0);
    for(int i=0;i<amount+1;i++)
    {
        if(i%coins[0]==0)dp[i]=i/coins[0];
        else dp[i]=1e9;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<amount+1;j++)
        {
            int take=INT_MAX;
            if(j>=coins[i])take=1+dp[j-coins[i]];
            int not_take=dp[j];
            dp[j]=min(take,not_take);
        }
    }
    return (dp[amount]>=1e9)?-1:dp[amount];
}
// int coinChange(vector<int> &coins, int amount)
// {
//     int n = coins.size();
//     vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
//     // int ans = util(coins, amount, n - 1, dp);
//     // if (ans >= 1e9)
//     //     return -1;
//     // return ans;
//     for(int i=0;i<amount+1;i++)
//     {
//         if(i%coins[0]==0)dp[0][i]=i/coins[0];
//         else dp[0][i]=1e9;
//     }
//     for(int i=1;i<n;i++)
//     {
//         for(int j=0;j<amount+1;j++)
//         {
//             int take=INT_MAX;
//             if(j>=coins[i])take=1+dp[i][j-coins[i]];
//             int not_take=dp[i-1][j];
//             dp[i][j]=min(take,not_take);
//         }
//     }
//     return (dp[n-1][amount]>=1e9)?-1:dp[n-1][amount];
// }
int main()
{
    // vector<int> coins = {2};
    vector<int> coins = {186, 419, 83, 408};
    // vector<int>coins={1,2,5};
    // cout << coinChange(coins, 3);
    cout << coinChange(coins, 6249);
    // cout << coinChange(coins, 11);
}