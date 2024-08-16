#include <bits/stdc++.h>
using namespace std;
int util(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int i, int jl, int jr)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i == n)
        return 0;
    if (jl < 0 || jl >= m || jr < 0 || jr >= m)
        return 0;
    if (jl == jr)
        return 0;
    if (dp[i][jl][jr] != -1)
        return dp[i][jl][jr];

    int temp = 0;
    for (int dl = -1; dl < 2; dl++)
    {
        for (int dr = -1; dr < 2; dr++)
        {
            temp = max(temp, util(grid, dp, i + 1, jl + dl, jr + dr));
        }
    }
    return dp[i][jl][jr] = temp + grid[i][jl] + grid[i][jr];
}
int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return util(grid, dp, 0, 0, m - 1);
}