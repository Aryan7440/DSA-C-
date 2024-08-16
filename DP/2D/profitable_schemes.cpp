#include <bits/stdc++.h>
using namespace std;

int util(int minProfit, vector<int> &group, vector<int> &profit, int i, int p, int n, vector<vector<vector<int>>> &dp)
{
    if (i == group.size())
    {
        if (p >= minProfit)
            return 1;
        return 0;
    }
    if (dp[i][p][n] != -1)
    {
        return dp[i][p][n];
    }
    int take = 0;
    if (n >= group[i])
    {
        take = util(minProfit, group, profit, i + 1, min(minProfit, p + profit[i]), n - group[i], dp);
    }
    int not_take = util(minProfit, group, profit, i + 1, p, n, dp);
    return dp[i][p][n] = take + not_take;
}
int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
    int m = group.size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(minProfit + 1, vector<int>(n+1, -1)));
    return util(minProfit, group, profit, 0, 0, n, dp);
}
int main()
{
    int n = 5,minProfit = 3;
    vector<int>  group = {2,2}, profit = {2,3};
    // int n = 10, minProfit = 5;
    // vector<int> group = {2, 3, 5}, profit = {6, 7, 8};
    cout << profitableSchemes(n, minProfit, group, profit);
    // int a=-1;
    // cout<<(a!=-1);
}