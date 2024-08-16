#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &prices, int ind, int buy, int count, vector<vector<vector<int>>> &dp)
{
    if (ind == prices.size() || count == 2)
        return 0;
    if (dp[ind][buy][count] != -1)
        return dp[ind][buy][count];
    if (buy)
    {
        return dp[ind][buy][count] = max(-prices[ind] + util(prices, ind + 1, 0, count, dp), util(prices, ind + 1, 1, count, dp));
    }
    return dp[ind][buy][count] = max(prices[ind] + util(prices, ind + 1, 1, count + 1, dp), util(prices, ind + 1, 0, count, dp));
}
// int maxProfit(vector<int> &prices)
// {
//     int n = prices.size();
//     // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
//     // return util(prices,0,1,0,dp);
//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             for (int k = 1; k >= 0; k--)
//             {
//                 if (j == 1)
//                     dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
//                 else
//                     dp[i][j][k] = max(prices[i] + dp[i + 1][1][k + 1], dp[i + 1][0][k]);
//             }
//         }
//     }
//     return dp[0][1][0];
// }
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         for (int k = 1; k >= 0; k--)
    //         {
    //             if (j == 1)
    //                 dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
    //             else
    //                 dp[i][j][k] = max(prices[i] + dp[i + 1][1][k + 1], dp[i + 1][0][k]);
    //         }
    //     }
    // }
    // return dp[0][1][0];

    vector<vector<int>>ahead(2, vector<int>(3, 0)),curr(2, vector<int>(3, 0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=1;k>=0;k--)
            {
                if(j==1)curr[j][k]=max(-prices[i]+ahead[0][k],ahead[1][k]);
                else curr[j][k]=max(prices[i]+ahead[1][k+1],ahead[0][k]);

            }
        }
        ahead=curr;
    }
    return ahead[1][0];

}
int main()
{
    vector<int> prices={3,3,5,0,0,3,1,4};
    cout<<maxProfit(prices);
}