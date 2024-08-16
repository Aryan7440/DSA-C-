#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dfs(vector<vector<int>> &adj, int u, int n, vector<int> &dist)
{
    if (dist[u] != -1)
    {
        return dist[u];
    }
    if (u == n)
    {
        return dist[u] = 1;
    }
    int ans = -1;
    for (auto v : adj[u])
    {

        ans = max(ans, dfs(adj, v, n, dist) + 1);
    }
    dist[u] = ans;
    return ans;
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
    }
    vector<int> dist(n + 1, -1);
    vector<bool> vis(n + 1, false);
    int ans = dfs(adj, 1, n + 1, dist);

    // if (ans == -1)
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    // cout << ans + 1 << endl;
    return 0;
}
