#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ocean(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ocean[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < m + 1; i++)
    {
        vis[0][i] = 1;
        q.push({0, i});
    }
    for (int i = 1; i < n; i++)
    {
        vis[i][0] = 1;
        q.push({i, 0});
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && ocean[nx][ny] >= ocean[x][y])
            {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i][m - 1] == 1)
            vis[i][m - 1] = 3;
        else
            vis[i][m - 1] = 2;
        q.push({i, m - 1});
    }
    for (int i = 0; i < m - 1; i++)
    {
        if (vis[n - 1][i] == 1)
            vis[n - 1][i] = 3;
        else
            vis[n - 1][i] = 2;
        q.push({n - 1, i});
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] < 2 && ocean[nx][ny] >= ocean[x][y])
            {
                if (vis[nx][ny] == 1)
                {
                    vis[nx][ny] = 3;
                }
                else
                    vis[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 3)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
