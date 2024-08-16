#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<int> dist;
vector<vector<int>> adj;
vector<int> path;
int flag;
int cs, ce;
bool dfs(int src, int par)
{
    vis[src] = 1;
    for (auto v : adj[src])
    {
        if (!vis[v])
        {
            path[v] = src;
            if (dfs(v, src))
                return true;
        }
        else if (v != par)
        {
            ce = v;
            cs = src;
            return true;
        }
    }
    // path[]
    return false;
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
    int node;
    cs = -1, ce = -1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
                break;
        }
    }
    if (cs == -1 || ce == -1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> ans;
    int p = cs;
    while (p != path[ce])
    {
        ans.push_back(p);
        p = path[p];
    }
    ans.push_back(cs);
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}