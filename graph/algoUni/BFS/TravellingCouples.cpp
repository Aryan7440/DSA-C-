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

    int c1, c2, c3, n, m;
    cin >> c1 >> c2 >> c3 >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d1 = bfs(adj, 1);
    vector<int> d2 = bfs(adj, 2);
    vector<int> d3 = bfs(adj, n);
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int cost = c1 * d1[i] + c2 * d2[i] + c3 * d3[i];
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}