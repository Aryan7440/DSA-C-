#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &adj, vector<int> &vis, int src)
{
    vis[src] = 0;
    int count = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(N + 1, -1);
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (vis[i] == -1)
        {
            bfs(adj, vis, i);
            ans++;
        }
    }
    cout << ans << endl;
}