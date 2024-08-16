#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool dfs(vector<vector<int>> &adj, vector<int> &vis, int node, int par)
{
    vis[node] = 1;
    bool res = false;
    for (auto i : adj[node])
    {
        if (i == par)
            continue;
        if (vis[i] == 1)
        {
            return true;
        }
        if (vis[i] == 0)
            res = res || dfs(adj, vis, i, node);
    }
    vis[node] = 2;
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(adj, vis, i, -1))
            {
                cycle = true;
                break;
            }
        }
    }
    if (cycle)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
