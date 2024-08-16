#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int node, vector<int> &vis, stack<int> &s)
{
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if(!vis[adj[node][i]])
        {
            dfs(adj, adj[node][i], vis, s);
        }
    }
    s.push(node);
}
// dfs
vector<int> topological_sort(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<int> vis(V, 0);
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(adj, i, vis, s);
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> adj={{},{},{3},{1},{0,1},{2,0}};
    vector<int> ans=topological_sort(adj);
    for(auto i:ans)cout<<i<<" ";
}