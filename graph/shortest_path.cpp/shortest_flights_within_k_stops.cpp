#include <bits/stdc++.h>
using namespace std;

// int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
// {
//     vector < vector<pair<int, int>>> adj(n);
//     for (auto i : flights)
//     {
//         adj[i[0]].push_back({i[1], i[2]});
//     }

//     priority_queue < pair<int, pair<int, int>>, vector < pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
//     vector<int> dist(n, INT_MAX);

//     q.push({0, {0, src}});
//     dist[src] = 0;

//     while (!q.empty())
//     {
//         auto t = q.top();
//         q.pop();
//         int stops = t.first;
//         int d = t.second.first;
//         int node = t.second.second;
//         if (stops > k)
//             continue;
//         for (auto i : adj[node])
//         {
//             if (dist[i.first] > d + i.second && stops<=k)
//             {
//                 dist[i.first] = d + i.second;
//                 q.push({stops + 1, {dist[i.first], i.first}});
//             }
//         }
//     }
//     return dist[dst] == INT_MAX ? -1 : dist[dst];
// }
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto i : flights)
    {
        adj[i[0]].push_back({i[1], i[2]});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {src, 0}});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int distanceTillNow = temp.first;
        int U = temp.second.first;
        int stops = temp.second.second;
        // if(U==dst)return distanceTillNow;
        if (stops > k)
            continue;
        for (auto v : adj[U])
        {
            int V = v.first;
            int d = v.second;
            if (stops <= k)
            {
                dist[V] = min(dist[V], distanceTillNow + d);
                pq.push({dist[V], {V, stops + 1}});
            }
        }
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
int main()
{
    vector<vector<int>> flights = {{0, 3, 3}, {3, 4, 3}, {4, 1, 3}, {0, 5, 1}, {5, 1, 100}, {0, 6, 2}, {6, 1, 100}, {0, 7, 1}, {7, 8, 1}, {8, 9, 1}, {9, 1, 1}, {1, 10, 1}, {10, 2, 1}, {1, 2, 100}};
    // vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << findCheapestPrice(11, flights, 0, 2, 4);
    // cout << findCheapestPrice(4, flights, 0, 3, 1);
}