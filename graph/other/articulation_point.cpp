#include <bits/stdc++.h>
using namespace std;

void dfs(int V, vector<int> adj[], vector<int> &dis, vector<int> &low, vector<int> &vis, int u, int par, int &time)
{
    vis[u] = 1;
    low[u] = dis[u] = time;
    time++;

    for (auto v : adj[u])
    {
        if (v == par)
            continue;
        if (!vis[v])
        {
            dfs(V, adj, dis, low, vis, v, u, time);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dis[u] && par != -1)
                vis[u] = 2;
        }
        else
        {
            low[u] = min(low[u], dis[v]);
        }
    }
}
vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> vis(V, 0), dis(V, 0), low(V, 0);
    int time = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(V, adj, dis, low, vis, i, -1, time);
    }
    if (adj[0].size() > 1)
        vis[0] = 2;
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 2)
            ans.push_back(i);
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}
int main()
{
    vector<int> adj[] = {{1},
                         {0, 4},
                         {3, 4},
                         {2, 4},
                         {1, 2, 3}};
    vector<int> ans=articulationPoints(5,adj);
    for(auto i:ans)cout<<i<<" ";                     
}