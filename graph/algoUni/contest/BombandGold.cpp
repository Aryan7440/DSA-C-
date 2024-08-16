#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<char>> mat(n, vector<char>(m));
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(b + 1, INT_MAX)));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {sx, sy}});
    dist[sx][sy][0] = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int k = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (mat[x][y] == 'G')
        {
            cout << dist[x][y][k] << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] != '#' && dist[x][y][k] + 1 < dist[nx][ny][k])
            {
                dist[nx][ny][k] = dist[x][y][k] + 1;
                q.push({k, {nx, ny}});
            }
            else if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == '#' && k < b && dist[x][y][k] + 1 < dist[nx][ny][k + 1])
            {
                dist[nx][ny][k + 1] = dist[x][y][k] + 1;
                q.push({k + 1, {nx, ny}});
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
