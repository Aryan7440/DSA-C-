#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(vector<string> &graph, vector<vector<int>> &vis, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});

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
                if (X >= 0 && Y >= 0 && X < graph.size() && Y < graph[x].size() && graph[X][Y] == '.' && !vis[X][Y])
                {
                    vis[X][Y] = 1;
                    q.push({X, Y});
                }
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> graph;
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            s.push_back(c);
        }
        graph.push_back(s);
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '.' && !vis[i][j])
            {
                vis[i][j] = 1;
                bfs(graph, vis, i, j);
                count++;
            }
        }
    }
    cout << count;
}

// input
// 3 10
// ..........
// #########.
// ..........