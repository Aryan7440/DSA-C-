#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
void dfs(vector<vector<int>> &grid, int len, int count, int &ans, int x, int y)
{
    int n = grid.size();
    int m = grid[0].size();

    if (grid[x][y] == 2)
    {
        if (count == len)
            ans++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < n && Y < m && X >= 0 && Y >= 0 && (grid[X][Y] == 0 || grid[X][Y] == 2))
        {
            int org = grid[x][y];
            grid[x][y] = -1;
            dfs(grid, len, count + 1, ans, X, Y);
            grid[x][y] = org;
        }
    }
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int sx = 0, sy = 0;
    int fy = -1, fx = -1;
    int obs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                fx = i;
                fy = j;
            }
            if (grid[i][j] == 1)
            {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == -1)
                obs++;
        }
    }
    int len = m * n - obs;
    int ans = 0;
    dfs(grid, len, 1, ans, sx, sy);
    return ans;
}