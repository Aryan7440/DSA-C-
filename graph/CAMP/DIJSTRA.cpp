#include <bits/stdc++.h>
using namespace std;
vector<int> DIJSTRA(vector<int> &hospitals, vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(adj.size(), -1);
    int n = adj.size();
    int d = 0;
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        if (hospitals[i])
            q.push({i, 0});
    }
    // q.push(source);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            int u = q.top().first;
            int distance = q.top().second;
            q.pop();
            dist[node] = d;
            for (int j = 0; j < adj[node].size(); j++)
            {
                int v = adj[node][j].first;
                int vd = adj[node][j].second;
                if (dist[v] > dist)
                    q.push(adj[node][j]);
            }
        }
        d++;
    }
    return dist;
}