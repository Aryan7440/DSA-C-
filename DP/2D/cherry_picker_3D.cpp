#include <bits/stdc++.h>
using namespace std;
int cherry_picker(vector<vector<int>> &grid, int i1, int j1, int j2, vector<vector<vector<int>>> &dp)
{
    int n = grid.size();
    int i2 = i1 + j1 - j2;
    if (i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
        return INT_MIN;
    if (i1 == n - 1 && j1 == n - 1)
        return grid[i1][j1];
    if (dp[i1][j1][j2] != -1)
        return dp[i1][j1][j2];
    int val = grid[i1][j1];
    if (j1 != j2)
        val += grid[i2][j2];

    int rr = cherry_picker(grid, i1, j1 + 1, j2 + 1, dp);
    int dd = cherry_picker(grid, i1 + 1, j1, j2, dp);
    int dr = cherry_picker(grid, i1 + 1, j1, j2 + 1, dp);
    int rd = cherry_picker(grid, i1, j1 + 1, j2, dp);
    int ans = max(max(rr, dd), max(dr, rd));
    ans += val;
    return dp[i1][j1][j2] = ans;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    return cherry_picker(grid, 0, 0, 0, dp);
}
int main()
{
    vector<vector<int>> grid = {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
    cout << cherryPickup(grid);
}