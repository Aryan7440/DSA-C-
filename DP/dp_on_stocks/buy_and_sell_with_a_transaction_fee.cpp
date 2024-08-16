#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<int> ahead(2,0),curr(2,0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                curr[j] = max(ahead[0] - prices[i], ahead[1]);
            }
            else
                curr[j] = max(ahead[1] + prices[i] - fee, ahead[0]);
        }
        ahead=curr;
    }
    return ahead[1];
}
// int maxProfit(vector<int> &prices, int fee)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n + 1, vector<int>(2, 0));

//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             if (j == 1)
//             {
//                 dp[i][j] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
//             }
//             else
//                 dp[i][j] = max(dp[i + 1][1] + prices[i] - fee, dp[i + 1][0]);
//         }
//     }
//     return dp[0][1];
// }