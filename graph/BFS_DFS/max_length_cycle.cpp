#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &edges, vector<int> &vis, vector<int> &dist, int node, int &ans)
{
    vis[node] = 1;

    int nb = edges[node];
    if (!vis[nb] && nb!=-1)
    {
        dist[nb] = dist[node] + 1;
        dfs(edges, vis, dist, nb, ans);
    }
    else if( nb!=-1)
    {
        ans = max(ans, dist[node] -dist[nb]  + 1);
    }
}
int longestCycle(vector<int> &edges)
{
    int n = edges.size();
    vector<int> vis(n, 0), dist(n, 0);
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            // dist[i] = 1;
            dfs(edges, vis, dist, i, ans);
        }
    }
    return ans;
}
int main()
{
    vector<int> edges={2,-1,3,1};
    // vector<int> edges={3,3,4,2,3};
    cout<<longestCycle(edges);
}