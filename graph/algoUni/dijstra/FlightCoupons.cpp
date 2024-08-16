#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }
    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
    vector<vector<long long>> dist(n + 1, vector<long long>(2, LONG_LONG_MAX));
    vector<vector<long long>> vis(n + 1, vector<long long>(2, 0));
    pq.push({0, {1, 1}});
    dist[1][1] = 0;
    dist[1][0] = 0;
    while (!pq.empty())
    {
        long long d = pq.top().first;
        long long u = pq.top().second.first;
        long long t = pq.top().second.second;
        pq.pop();
        if (vis[u][t])
            continue;
        vis[u][t] = 1;
        for (auto x : adj[u])
        {
            long long v = x.first;
            long long w = x.second;
            if (d + w < dist[v][t])
            {
                dist[v][t] = d + w;
                pq.push({dist[v][t], {v, t}});
            }
            if ((t == 1) && (d + (w / 2) < dist[v][0]))
            {
                dist[v][0] = d + (w / 2);
                pq.push({dist[v][0], {v, 0}});
            }
        }
    }
    long long ans = min(dist[n][0], dist[n][1]);
    cout << ans;

    return 0;
}