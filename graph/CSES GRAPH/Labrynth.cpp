#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};
// vector<vector<char>> pat;
bool bfs(vector<string> &graph, vector<vector<int>> &vis, vector<vector<char>> &pat, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 0;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto node = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int X = node.first + dx[j];
                int Y = node.second + dy[j];
                if (X >= 0 && Y >= 0 && X < graph.size() && Y < graph[x].size() && graph[X][Y] != '#' && vis[X][Y] == -1)
                {
                    pat[X][Y] = dir[j];
                    vis[X][Y] = vis[node.first][node.second] + 1;
                    if (graph[X][Y] == 'B')
                        return true;
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
    vector<string> graph;
    vector<vector<char>> pat(n, vector<char>(m));
    pair<int, int> src;
    pair<int, int> des;
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            s.push_back(c);
            if (c == 'A')
                src = {i, j};
            if (c == 'B')
                des = {i, j};
        }
        graph.push_back(s);
    }

    vector<vector<int>> vis(n, vector<int>(m, -1));
    bool ans = bfs(graph, vis, pat, src.first, src.second);
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

// input
// 3 10
// ..........
// #########.
// ..........