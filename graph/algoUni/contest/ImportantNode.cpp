#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (dist[v] == INT_MAX)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> d1 = shortestPath(adj, 1);
    vector<int> d2 = shortestPath(adj, n);
    for (int i = 1; i <= n; i++)
    {
        if (d1[i] + d2[i] == d1[n])
        {
            cout << i << " ";
        }
    }
    return 0;
}
