#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
void dfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, int x, int y)
{
    int n = grid.size();
    int m = grid[0].size();
    q.push({x, y});
    grid[x][y] = 2;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 && Y >= 0 && X < n && Y < m && grid[X][Y] == 1)
        {
            dfs(grid, q, X, Y);
        }
    }
}
int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, q, i, j);
                flag = 1;
                if (flag)
                    break;
            }
        }
        if (flag)
            break;
    }
    int count = 0;
    while (!q.empty())
    {
        int s = q.size();
        count++;
        for (int i = 0; i < s; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            for (int j = 0; j < 4; j++)
            {
                int X = x + dx[j];
                int Y = y + dy[j];
                if (X >= 0 && Y >= 0 && X < n && Y < m && grid[X][Y] != 2)
                {
                    if (grid[X][Y] == 1)
                        return count;
                    grid[X][Y] = 2;
                    q.push({X, Y});
                }
            }
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
    cout<<shortestBridge(grid);

}