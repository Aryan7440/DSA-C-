#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &edges, vector<int> &vis, vector<int> &dist, int &ans)
{
    vis[node] = 1;
    int neighbour = edges[node];
    if (neighbour == -1)
        return;
    if (!vis[neighbour])
    {
        dist[neighbour] = dist[node] + 1;
        dfs(neighbour, edges, vis, dist, ans);
    }
    else if (dist[neighbour] != -1)
    {
        ans = max(ans, dist[node] - dist[neighbour] + 1);
    }
}
int longestCycle(vector<int> &edges)
{
    int n = edges.size();
    vector<int> vis(n, 0);
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vector<int> dist(n, -1);
            int temp = 0;
            dist[i] = 0;
            dfs(i, edges, vis, dist, temp);
            ans = max(ans, temp);
        }
    }
    return ans;
}
int main()
{
    vector<int> edges={3,3,4,2,3};
    cout<<longestCycle(edges);
}