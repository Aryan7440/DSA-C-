#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<int> dist;
vector<vector<int>> adj;
vector<int> path;
int flag;
// int dist = 0;
bool bfs(int src)
{
    vis[src] = 1;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = (vis[u] == 1) ? 2 : 1;
                dist[v] = dist[u] + 1;
                path[v] = u;
                q.push(v);
            }
            else if (vis[v] == vis[u])
                return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1);
    path.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count = 0;
    flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (bfs(i) == false)
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
    cout << endl;
}