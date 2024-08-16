#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &prices, int ind, int buy, vector<vector<int>> &dp)
{
    if (ind >= prices.size())
        return 0;
    if (buy)
    {
        return dp[ind][buy] = max(util(prices, ind + 1, 0, dp) - prices[ind], util(prices, ind + 1, 1, dp));
    }
    return dp[ind][buy] = max(util(prices, ind + 2, 1, dp) + prices[ind], util(prices, ind + 1, 0, dp));
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // return util(prices,0,1,dp);

    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
                dp[i][j] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
            else
                dp[i][j] = max(dp[i + 2][1] + prices[i], dp[i + 1][0]);
        }
    }
    return dp[0][1];
}