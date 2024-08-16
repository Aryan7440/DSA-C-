#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<int> parent;
vector<int> vis;
void bfs(vector<vector<int>> &adj, int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dist[s] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = 1;
                dist[u] = dist[v] + 1;
                parent[u] = v;
                q.push(u);
            }
        }
    }
}
vector<int> printPath(int s, int v)
{
    vector<int> path;
    for (int i = v; i != s; i = parent[i])
    {
        path.push_back(i);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
int main()
{
    // int n, m;
    // cin >> n >> m;
    int n = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    vector<vector<int>> adj(n);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        // adj[e[1]].push_back(e[0]);
    }
    // for(int i = 0; i < m; i++){
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // int s;
    // cin >> s;
    int s = 0;
    vis.assign(n, 0);
    dist.assign(n, INT_MAX);
    parent.assign(n, -1);
    bfs(adj, s);
    for (int i = 0; i < n; i++)
    {
        cout << "Distance from " << s << " to " << i << " is " << dist[i] << endl;
        vector<int> path = printPath(s, i);
        cout << "Path: ";
        for (int x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}