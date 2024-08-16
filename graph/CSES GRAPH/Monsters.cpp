#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
pair<int, int> des;
vector<string> graph;
vector<vector<int>> vis;
vector<vector<char>> pat;

bool bfs(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            if (vis[x][y] != -2 && (x == 0 || y == 0 || x == graph.size() - 1 || y == graph[x].size() - 1))
            {
                des = {x, y};
                return true;
            }
            for (int j = 0; j < 4; j++)
            {
                int X = node.first + dx[j];
                int Y = node.second + dy[j];
                if (X >= 0 && Y >= 0 && X < graph.size() && Y < graph[x].size() && graph[X][Y] == '.' && vis[X][Y] == -1)
                {
                    if (vis[x][y] == -2)
                    {
                        vis[X][Y] = -2;
                    }
                    else
                    {
                        pat[X][Y] = dir[j];
                        vis[X][Y] = vis[x][y] + 1;
                        if (X == 0 || Y == 0 || X == graph.size() - 1 || Y == graph[x].size() - 1)
                        {
                            des = {X, Y};
                            return true;
                        }
                    }
                    q.push({X, Y});
                }
            }
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vis.resize(n, vector<int>(m, -1));
    pat.resize(n, vector<char>(m));
    pair<int, int> src;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            s.push_back(c);
            if (c == 'A')
            {
                // q.push({i, j});
                vis[i][j] = 0;
                src = {i, j};
            }
            else if (c == 'M')
            {
                q.push({i, j});
                vis[i][j] = -2;
            }
        }
        graph.push_back(s);
    }
    q.push(src);
    bool ans = bfs(q);
    if (ans)
    {
        cout << "YES" << endl;
        // cout << vis[des.first][des.second] << endl;
        pair<int, int> p = {des.first, des.second};
        string path = "";
        for (int i = vis[des.first][des.second]; i > 0; i--)
        {
            path.push_back(pat[p.first][p.second]);
            if (pat[p.first][p.second] == 'U')
                p = {p.first + 1, p.second};
            else if (pat[p.first][p.second] == 'L')
                p = {p.first, p.second + 1};
            else if (pat[p.first][p.second] == 'D')
                p = {p.first - 1, p.second};
            else if (pat[p.first][p.second] == 'R')
                p = {p.first, p.second - 1};
        }
        cout << vis[des.first][des.second] << endl;
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
    else
        cout << "NO" << endl;
}
