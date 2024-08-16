#include <bits/stdc++.h>
using namespace std;
vector<long long> dist;
long long INF = LONG_LONG_MAX;

void Dijkstra(vector<vector<pair<int, long long>>> &edges, int src)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        long long dist_till_now = pq.top().first;
        pq.pop();
        if (dist_till_now != dist[u])
            continue;
        for (auto e : edges[u])
        {
            int v = e.first;
            long long w = e.second;
            if (dist_till_now + w < dist[v])
            {
                dist[v] = dist_till_now + w;
                pq.push({dist[v], v});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> edges(n + 1);
    dist.resize(n + 1, INF);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        // edges[v].push_back({u, w});
    }
    Dijkstra(edges, 1);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}