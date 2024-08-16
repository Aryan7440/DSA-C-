#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, vector<int> &di, vector<int> &dj, int x, int y, int &len)
{
    len++;
    int n = grid.size();
    int m = grid[0].size();
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int X = x + di[i];
        int Y = y + dj[i];
        if (X < n && X >= 0 && Y < m && Y >= 0 && grid[X][Y] == 1)
            dfs(grid, di, dj, X, Y, len);
    }
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max_len = 0;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                int len = 0;
                dfs(grid, di, dj, i, j, len);
                max_len = max(len, max_len);
            }
        }
    }
    return max_len;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout<<maxAreaOfIsland(grid);
}