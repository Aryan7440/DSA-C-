#include <bits/stdc++.h>
using namespace std;

int main()
{

    // cout << "Hello World";
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, k}});
    vis[0][0][k] = 1;
    int dist = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second.first;
            int K = node.second.second;
            for (int j = 0; j < 4; j++)
            {
                int X = x + dx[j];
                int Y = y + dy[j];
                if (X >= 0 && Y >= 0 && X < grid.size() && Y < grid[x].size() && vis[X][Y][K] == 0)
                {
                    if (grid[X][Y] == 1 && K > 0)
                    {
                        q.push({X, {Y, K - 1}});
                        vis[X][Y][K - 1] = vis[x][y][K] + 1;
                        if (X == grid.size() - 1 && Y == grid[x].size() - 1)
                        {
                            cout << vis[X][Y][K - 1] - 1 << endl;
                            return 0;
                        }
                    }
                    else if (grid[X][Y] == 0)
                    {
                        vis[X][Y][K] = vis[x][y][K] + 1;
                        q.push({X, {Y, K}});
                        if (X == grid.size() - 1 && Y == grid[x].size() - 1)
                        {
                            cout << vis[X][Y][K] - 1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}