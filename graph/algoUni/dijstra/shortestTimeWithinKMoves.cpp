#include <bits/stdc++.h>
using namespace std;
// chocolate problem 1
double minimumTime(vector<vector<pair<int, int>>> &adj, int src, int des, int k)
{
    int n = adj.size();
    vector<vector<int>> vis(n, vector<int>(k + 1, 0));
    vector<vector<double>> dist(n, vector<double>(k + 1, 1e9 * 1.0));
    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>, greater<tuple<double, int, int>>> pq;
    pq.push({0, src, 0});
    dist[src][0] = 0;
    while (!pq.empty())
    {
        auto [time, node, move] = pq.top();
        pq.pop();
        if (node == des)
            return time;
        if (vis[node][move])
            continue;
        vis[node][move] = 1;
        for (auto &[child, wt] : adj[node])
        {
            if (move + 1 <= k and time + (double)wt / 2 < dist[child][move + 1])
            {
                dist[child][move + 1] = time + (double)wt / 2;
                pq.push({time + (double)wt / 2, child, move + 1});
            }
            if (dist[child][move] > time + wt)
            {
                dist[child][move] = time + wt;
                pq.push({time + wt, child, move});
            }
        }
    }
    return -1;
}
int main()
{

    vector<vector<pair<int, int>>> adj = {{{1, 3}, {2, 10}},
                                          {{0, 3}, {3, 4}},
                                          {{0, 10}, {3, 1}},
                                          {{1, 4}, {2, 1}}};

    int src = 0, des = 3, k = 2;
    cout << minimumTime(adj, src, des, k);
}