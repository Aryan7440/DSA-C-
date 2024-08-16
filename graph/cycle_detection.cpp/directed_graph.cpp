#include <bits/stdc++.h>
using namespace std;
bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &prevnodes)
{
    vis[i] = 1;
    prevnodes[i] = 1;
    for (auto node : adj[i])
    {
        if (!vis[node])
        {
            if (dfs(node, adj, vis, prevnodes))
                return true;
        }
        else if (prevnodes[node])
        {
            return true;
        }
    }
    prevnodes[i] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> prevnodes(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, prevnodes))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> adj[] = {{1}, {2}, {3}, {3}, {4}};
    cout << isCyclic(5, adj);
}