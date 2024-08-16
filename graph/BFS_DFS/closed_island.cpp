#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, vector<int> &di, vector<int> &dj, int x, int y, int &flag)
{
    // len++;
    int n = grid.size();
    int m = grid[0].size();
    grid[x][y] = 2;
    if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        flag = 1;
    for (int i = 0; i < 4; i++)
    {
        int X = x + di[i];
        int Y = y + dj[i];
        if (X < n && X >= 0 && Y < m && Y >= 0 && grid[X][Y] == 0)
        {
            dfs(grid, di, dj, X, Y, flag);
        }
    }
}
int closedIsland(vector<vector<int>> &grid)
{
    int count = 0;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                int flag = 0;
                dfs(grid, di, dj, i, j, flag);
                if (!flag)
                    count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                                {1, 0, 0, 0, 0, 1, 1, 0},
                                {1, 0, 1, 0, 1, 1, 1, 0},
                                {1, 0, 0, 0, 0, 1, 0, 1},
                                {1, 1, 1, 1, 1, 1, 1, 0}};
    cout << closedIsland(grid);
}