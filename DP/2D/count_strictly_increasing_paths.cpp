#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int util(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    int n = grid.size();
    int m = grid[i].size();
    if (dp[i][j] != -1)
        return dp[i][j];
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    int count = 1;
    for (int k = 0; k < 4; k++)
    {
        int I = i + di[k];
        int J = j + dj[k];
        if (I < n && J < m && I >= 0 && J >= 0 && grid[i][j] < grid[I][J])
        {
            count += util(grid, I, J, dp) % mod;
            count = count % mod;
        }
    }
    return dp[i][j] = count % mod;
}
int countPaths(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += util(grid, i, j, dp) % mod;
            ans = ans % mod;
        }
    }
    // ans += (m * n) % mod;
    return ans % mod;
}
