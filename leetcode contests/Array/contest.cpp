#include <bits/stdc++.h>
using namespace std;

    vector<int> res(vector<vector<pair<int, int>>> &graph, int src)
{
    vector<int> dist(graph.size(), INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : graph[u])
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
{
    int n = edges.size();
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto x : edges)
    {
        graph[x[0]].push_back({x[1], x[2]});
        graph[x[1]].push_back({x[0], x[2]});
    }
    vector<int> ans(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        vector<int> dist = res(graph, i);
        int c1 = 0;
        for (int j = 0; j < i; j++)
        {
            if (dist[j] % signalSpeed == 0)
            {
                c1++;
            }
        }
        int c2 = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (dist[j] % signalSpeed == 0)
            {
                c2++;
            }
        }
        ans[i] = c1 * c2;
    }
    return ans;
}
int main()
{
    // vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}};
    // vector<int> ans = countPairsOfConnectableServers(edges, 1);
    vector<vector<int>> edges1 = {{0, 6, 3}, {6, 5, 3}, {0, 3, 1}, {3, 2, 7}, {3, 1, 6}, {3, 4, 2}};
    vector<int> ans = countPairsOfConnectableServers(edges1, 3);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}