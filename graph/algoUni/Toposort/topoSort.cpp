#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j : adj[i])
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return order;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> order = topoSort(adj);
    for (int i : order)
    {
        cout << i << " ";
    }
}