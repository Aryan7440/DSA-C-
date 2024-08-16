#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dist;
int INF = INT_MAX;

void FloyedWarshall(vector<vector<pair<int, int>>> &edges)
{
    int n = edges.size();
    dist.resize(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < edges[i].size(); j++)
        {
            dist[i][edges[i][j].first] = min(dist[i][edges[i][j].first], edges[i][j].second);
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    FloyedWarshall(edges);
    for (int i = 1; i <= n; i++)
        cout << dist[1][i] << " ";
}