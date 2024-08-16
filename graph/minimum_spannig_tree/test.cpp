#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    vector<int> dist(V, 0);
    int distance=0;
    pq.push({0, 0});
    vis[0] = 1;
    while (!pq.empty())
    {
        auto p = pq.top();
        int d = p.first;
        int node = p.second;
        pq.pop();
        if (!vis[node])
        {
            vis[node] = 1;
            dist[node] = d;
        }
        for (auto i : adj[node])
        {
            if (!vis[i[0]])
                pq.push({i[1], i[0]});
        }
    }
    for (auto i : dist)
        distance += i;
    return distance;
}

int main()
{
    vector<vector<int>> edges = { {0, 1, 7},
                                  {0, 4, 4},
                                  {0, 7, 8},
                                  {0, 9, 3},
                                  {1, 7, 7},
                                  {1, 8, 3},
                                  {2, 5, 8},
                                  {2, 7, 10},
                                  {3, 4, 3},
                                  {4, 6, 10},
                                  {5, 7, 8} };
    int V=edges.size();
    vector<vector<int>> adj[V];
    for(auto i:edges)
    {
        adj[i[0]].push_back({i[1],i[2]});
        adj[i[1]].push_back({i[0],i[2]});
    }
    cout<<spanningTree(V,adj);
}