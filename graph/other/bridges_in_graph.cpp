#include <bits/stdc++.h>
using namespace std;
void dfs(int n, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dis, vector<int> &low, int u,int par, int &time, vector<vector<int>> &ans)
{
    vis[u] = 1;
    time++;
    dis[u] = time;
    low[u] = time;

    for (auto v : adj[u]) // u->v
    {
        if (!vis[v])
        {
            dfs(n, adj, vis, dis, low, v,u, time, ans);
            low[u] = min(low[u], low[v]);
            if (low[v] > dis[u])
                ans.push_back({u, v});
        }
        else if(v!=par)
        {
            low[u] = min(low[u], dis[v]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n);
    for (auto i : connections)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> vis(n, 0), dis(n, 0), low(n, 0);
    vector<vector<int>> ans;
    int time = 0;

    dfs(n, adj, vis, dis, low, 0,-1, time, ans);
    return ans;
}

int main()
{
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int n = 4;
    vector<vector<int>> ans=criticalConnections(n,connections);
    for(auto i:ans)cout<<i[0]<<"-"<<i[1]<<endl;
}