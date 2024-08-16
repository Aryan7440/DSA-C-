#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &prices, int ind, int buy, int k, vector<vector<vector<int>>> &dp)
{
    if (ind == prices.size() || k == 0)
        return 0;
    if (dp[ind][buy][k] != -1)
        return dp[ind][buy][k];
    if (buy)
    {
        return dp[ind][buy][k] = max(util(prices, ind + 1, 0, k, dp) - prices[ind], util(prices, ind + 1, 1, k, dp));
    }
    return dp[ind][buy][k] = max(prices[ind] + util(prices, ind + 1, 1, k - 1, dp), util(prices, ind + 1, 0, k, dp));
}
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n , vector<vector<int>>(2, vector<int>(k + 1, -1)));
    // return util(prices,0,1,k,dp);

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int ko = 1; ko <= k; ko++)
            {
                if (j == 1)
                {
                    dp[i][j][ko] = max(dp[i + 1][0][ko] - prices[i], dp[i + 1][1][ko]);
                }
                else
                    dp[i][j][ko] = max(prices[i] + dp[i + 1][1][ko - 1], dp[i + 1][0][ko]);
            }
        }
    }
    return dp[0][1][k];
}