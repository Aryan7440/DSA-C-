#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &adj, int s)
{
    queue<int> q;
    q.push(s);
    int n = adj.size();
    vector<int> dist(n, 0);
    vector<int> vis(n, 0);
    vis[s] = 1;
    dist[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
int main()
{

    int n, m;
    cin >> n >> m;
    int src, des;
    cin >> src >> des;
    vector<int> cur(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> cur[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (cur[v] || cur[u])
            continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist = bfs(adj, 0);
    if (dist[des] == 0 && des != 0)
        cout << -1 << endl;
    else
        cout << dist[des] << endl;

    return 0;
}