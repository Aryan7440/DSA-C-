#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[u] = true;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, adj, vis);
        }
    }
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
    int count = 0;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adj, vis);
        }
    }
    cout << count - 1 << endl;

    return 0;
}
