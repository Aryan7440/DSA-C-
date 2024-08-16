#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj, vector<int> &vis, int x, int colour)
{
    vis[x] = colour;
    int next = (colour == 1) ? 2 : 1;
    for (auto i : adj[x])
    {
        if (!vis[i])
        {
            if (!dfs(adj, vis, i, next))
                return false;
        }
        else
        {
            if (vis[i] != next)
                return false;
        }
    }
    return true;
}
bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<vector<int>> adj(n + 1);
    for (auto i : dislikes)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> vis(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(adj, vis, i, 1) != true)
                return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> dislikes={{1,2},{1,3},{2,4}};
    cout<<possibleBipartition(4,dislikes);
}