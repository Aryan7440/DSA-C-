#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &adj, int node, int dist, int signalSpeed, vector<int> &vis, int &count)
{
    vis[node] = 1;
    if (dist % signalSpeed == 0 && dist != 0)
        count++;
    for (auto i : adj[node])
    {
        if (!vis[i.first])
        {
            dfs(adj, i.first, dist + i.second, signalSpeed, vis, count);
        }
    }
}

vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
{
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> adj(n);
    for (auto i : edges)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {

        // int count=0;
        int c = 0;
        int C = 1;
        int ts = 0;
        for (auto p : adj[i])
        {
            vector<int> vis(n, 0);
            int count = 0;
            vis[i] = 1;
            dfs(adj, p.first, p.second, signalSpeed, vis, count);
            C = ts * count;
            ts += count;
        }
        ans[i] = ts;
    }
    return ans;
}
int main()
{
    // vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}};
    // int signalSpeed = 1;
    vector<vector<int>> edges = {{0, 6, 3}, {6, 5, 3}, {0, 3, 1}, {3, 2, 7}, {3, 1, 6}, {3, 4, 2}};
    int signalSpeed = 3;
    vector<int> ans = countPairsOfConnectableServers(edges, signalSpeed);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}