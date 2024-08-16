#include <bits/stdc++.h>
using namespace std;
int util(vector<vector<int>> &piles, int k, int i, vector<vector<int>> &dp)
{
    if (i == piles.size())
        return 0;
    if (k == 0)
        return 0;
    // int ans = 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    int temp = 0;
    int size = piles[i].size();
    int ans = util(piles, k, i + 1, dp);
    int cantake = min(k, size);
    for (int j = 0; j < cantake; j++)
    {
        temp = temp + piles[i][j];
        int take = util(piles, k - j - 1, i + 1, dp);
        ans = max(ans, temp + take);
    }
    return dp[i][k] = ans;
}
int maxValueOfCoins(vector<vector<int>> &piles, int k)
{
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return util(piles, k, 0, dp);
}
int main()
{
    vector<vector<int>> piles = {{1, 100, 3}, {7, 8, 9}};
    int k = 2;
    cout << maxValueOfCoins(piles, k);
}