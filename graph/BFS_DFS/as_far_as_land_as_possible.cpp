#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                q.push({i, j});
        }
    }
    int dist = -1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while (!q.empty())
    {
        int m = q.size();
        dist++;
        for (int i = 0; i < m; i++)
        {
            auto p = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int X = p.first + dx[j];
                int Y = p.second + dy[j];
                if (X < n && X >= 0 && Y < n && Y >= 0 && grid[X][Y] == 0)
                {
                    q.push({X, Y});
                    grid[X][Y] = 1;
                }
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    cout<<maxDistance(grid);
}