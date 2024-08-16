#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &prices, int buy, int ind, vector<vector<int>> &dp)
{
    if (ind == prices.size())
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        return dp[ind][buy] = max(-(prices[ind]) + util(prices, 0, ind + 1, dp), util(prices, 1, ind + 1, dp));
    }
    return dp[ind][buy] = max(prices[ind] + util(prices, 1, ind + 1, dp), util(prices, 0, ind + 1, dp));
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> dp(2,0);
    dp[0] = dp[1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
                dp[j] = max(-prices[i] + dp[0], dp[1]);
            else
                dp[j] = max(prices[i] + dp[1], dp[0]);
        }
    }
    return dp[1];
}
// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n + 1, vector<int>(2, -1));
//     // return util(prices,1,0,dp);
//     dp[n][0] = dp[n][1] = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             if (j == 1)
//                 dp[i][j] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
//             else
//                 dp[i][j] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
//         }
//     }
//     return dp[0][1];
// }
int main()
{
    vector<int> prices = {2, 1, 2, 0, 1};
    cout << maxProfit(prices);
}