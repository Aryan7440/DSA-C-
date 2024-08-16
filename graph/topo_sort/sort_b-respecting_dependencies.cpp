#include <bits/stdc++.h>
using namespace std;
vector<int> topo(vector<vector<int>> &adj)
{
    vector<int> indegree(adj.size(), 0);
    for (auto i : adj)
    {
        for (auto j : i)
            indegree[j] += 1;
    }

    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        topo.push_back(q.front());
        q.pop();
        for (auto i : adj[topo.back()])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return topo;
}
vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
{
    vector<vector<int>> graph(m + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < beforeItems[i].size(); j++)
        {
            int v = group[i]+1; // u->v
            int u = group[beforeItems[i][j]]+1;

            if(u!=v)graph[u].push_back(v);
        }
    }
    vector<int> grp_order = topo(graph);
    // return grp_order;


    // sort elements
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<beforeItems[i].size();j++)
        {
            adj[beforeItems[i][j]].push_back(i);
        }
    }
    vector<int> it_order=topo(adj);
    return it_order;
}
int main()
{
    int n = 8, m = 2;
    vector<int> group = {-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};
    vector<int> ans=sortItems(n,m,group,beforeItems);
    for(auto i:ans)cout<<i<<" ";
}