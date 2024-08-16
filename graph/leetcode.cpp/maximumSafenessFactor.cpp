#include <bits/stdc++.h>
using namespace std;
int maximumSafenessFactor(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                q.push({i, j});
                grid[i][j]=-1;
            }
        }
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int dist = 1;
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            int x = q.front().first;
            int y = q.front().second;
            // if(grid[x][y]==-1)grid[x][y]=0;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int X = x + dx[k];
                int Y = y + dy[k];

                if (X >= 0 && Y >= 0 && X < n && Y < n && grid[X][Y] == 0)
                {
                    grid[X][Y] = dist;
                    q.push({X, Y});
                }
            }
        }
        dist++;
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({grid[0][0], {0, 0}});
    grid[0][0] = -2;

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int m = p.first;
        int x = p.second.first;
        int y = p.second.second;
        if (x == n - 1 && y == n - 1)
            return m==-1?0:m;
        for (int k = 0; k < 4; k++)
        {
            int X = x + dx[k];
            int Y = y + dy[k];

            if (X >= 0 && Y >= 0 && X < n && Y < n && grid[X][Y] != -2)
            {
                int M = min(grid[X][Y], m);
                grid[X][Y] = -2;
                pq.push({M, {X, Y}});
            }
        }
    }
    return 0;
}
int main()
{
    // vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    vector<vector<int>> grid = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    cout<<maximumSafenessFactor(grid);
}