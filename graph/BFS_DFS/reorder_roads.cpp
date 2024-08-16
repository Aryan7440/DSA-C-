#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &adj, vector<int> &vis, int x, int &count)
{
    vis[x] = 1;
    for (auto i : adj[x])
    {
        if (!vis[i.first] )
        {
            if(i.second==1)count++;
            dfs(adj, vis, i.first, count);
        }
    }
}
int minReorder(int n, vector<vector<int>> &connections)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto i : connections)
    {
        adj[i[0]].push_back({i[1], 1});
        adj[i[1]].push_back({i[0], 0});
    }
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(adj, vis, i, count);
    }
    return count;
}

int main()
{
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    cout << minReorder(6, connections);
}