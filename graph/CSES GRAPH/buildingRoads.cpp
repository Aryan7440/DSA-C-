#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<vector<int>> adj;
void bfs(int src)
{
    vis[src] = 1;
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
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int roads = 0;
    bfs(1);
    vector<int> nodes;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            roads++;
            nodes.push_back(i);
            bfs(i);
        }
    }
    cout << roads << endl;
    for (auto i : nodes)
    {
        cout << 1 << " " << i << endl;
    }
}