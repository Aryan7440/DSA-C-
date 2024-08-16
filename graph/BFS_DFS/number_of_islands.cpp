#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, vector<int> &di, vector<int> &dj, int x, int y)
{
    int n = grid.size();
    int m = grid[0].size();
    grid[x][y] = '0';
    for (int i = 0; i < 4; i++)
    {
        int X = x + di[i];
        int Y = y + dj[i];
        if (X < n && X >= 0 && Y < m && Y >= 0 && grid[X][Y] == '1')
            dfs(grid, di, dj, X, Y);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                dfs(grid, di, dj, i, j);
            }
        }
    }
    return islands;
}
int main()
{
    vector<vector<char>>grid={{'1'},{'1'}};
    cout<<numIslands(grid);
}