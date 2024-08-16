#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in an undirected graph.
bool dfs(int s, int p, vector<vector<int>> adj, vector<int> &visited)
{
    visited[s] = 1;
    // bool ans = false;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!visited[i])
        {
            if (dfs(i, s, adj, visited))
                return true;
        }
        else if (i != p)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<vector<int>> adj)
{
    // Code here
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj = {{}, {2}, {1, 3}, {2}};
    // vector<vector<int>> adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    cout << isCycle(4, adj);
}