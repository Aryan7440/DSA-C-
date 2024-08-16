#include <bits/stdc++.h>
using namespace std;
int util(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[ind] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int take = 0;
    if (amount >= coins[ind])
        take = util(ind, amount - coins[ind], coins, dp);
    int not_take = util(ind - 1, amount, coins, dp);
    return dp[ind][amount] = take + not_take;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // return util(n - 1, amount, coins, dp);
    vector<int> dp(amount + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (i == 0)
                dp[j] = !(j % coins[i]);
            else
            {
                int take=(j-coins[i]>=0)?dp[j-coins[i]]:0;
                int not_take=dp[j];
                dp[j]=take+not_take;
            }
        }
    }
    return dp[amount];
}
int main()
{
}