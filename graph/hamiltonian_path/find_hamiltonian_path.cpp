#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj, int node, vector<int> &vis, int &count)
{
    vis[node] = 1;
    count++;
    if (count == adj.size() - 1)
        return true;
    bool res = false;
    for (auto n : adj[node])
    {
        if (!vis[n] && dfs(adj, n, vis, count))
            return true;
    }
    vis[node] = 0;
    count--;
    return false;
}
bool check(int N, int M, vector<vector<int>> Edges)
{
    // code here
    vector<vector<int>> adj(N + 1);
    for (auto i : Edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> vis(N + 1, 0);
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        // vector<int> Path;
        if (dfs(adj, i, vis, count))
            return true;
    }
    return false;
}
int main()
{
    int N = 10, M = 14;
    vector<vector<int>> edges = {{2, 1},
                                 {10, 2},
                                 {6, 3},
                                 {5, 4},
                                 {10, 5},
                                 {10, 6},
                                 {6, 7},
                                 {6, 8},
                                 {10, 9},
                                 {4, 9},
                                 {3, 8},
                                 {3, 7},
                                 {5, 9},
                                 {6, 5}};
    cout<<check(N,M,edges);
}