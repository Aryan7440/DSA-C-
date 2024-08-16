#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &adj, vector<bool> &hasApple, int x)
{
    int total = 0;
    for (auto i : adj[x])
    {
        int below = dfs(adj, hasApple, i);
        if (below || hasApple[i])
            total += below + 2;
    }
    return total;
}
int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    vector<vector<int>> adj(n);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }
    return dfs(adj, hasApple, 0);
}
int main()
{
    vector<vector<int>> edges={{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple={false,false,true,false,true,true,false};
    cout<<minTime(7,edges,hasApple);
}