#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<int> dist;
vector<vector<int>> adj;
vector<int> path;
// int dist = 0;
void bfs(int src)
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
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                path[v] = u;
                q.push(v);
            }
        }
    }
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

    bfs(1);
    // for(int i)
    if (!vis[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << dist[n] + 1 << endl;
    int p = n;
    vector<int> ans;
    while (p != 0)
    {
        // cout << p << " ";
        ans.push_back(p);
        p = path[p];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}