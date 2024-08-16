#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> slowness_factor(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> slowness_factor[i];
        }
        vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, LONG_LONG_MAX));

        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
        pq.push({0, {1, 1}});
        dist[1][1] = 0;

        while (!pq.empty())
        {
            pair<long long, pair<int, int>> node = pq.top();
            pq.pop();
            long long dist_till_now = node.first;
            int u = node.second.first;
            int bike = node.second.second;

            for (auto nb : adj[u])
            {
                int v = nb.first;
                int w = nb.second;
                if (dist[v][bike] > dist_till_now + (w * slowness_factor[bike]))
                {
                    dist[v][bike] = dist_till_now + (w * slowness_factor[bike]);
                    pq.push({dist[v][bike], {v, bike}});
                }
            }
            if (slowness_factor[bike] > slowness_factor[u])
                pq.push({dist_till_now, {u, u}});
        }
        long long ans = LONG_LONG_MAX;
        for (int i = 1; i <= n; i++)
            ans = min(ans, dist[n][i]);

        cout << ans << endl;
    }
}