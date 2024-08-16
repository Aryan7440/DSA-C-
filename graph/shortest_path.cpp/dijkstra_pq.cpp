#include <bits/stdc++.h>
using namespace std;
// vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
// {
//     vector<int> distance(V, INT_MAX);
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     distance[S] = 0;
//     pq.push({S, 0}); // source

//     while (!pq.empty())
//     {
//         pair<int, int> node = pq.top();
//         pq.pop();
//         for (auto adj_ : adj[node.first])
//         {
//             if (distance[adj_[0]] > node.second + adj_[1])
//             {
//                 distance[adj_[0]] = node.second + adj_[1];
//                 pq.push({adj_[0], distance[adj_[0]]});
//             }
//         }
//     }
//     return distance;
// }
vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int src)
{
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[src] = 0;
    pq.push({0, src}); // source// pq stores by min first element of pair

    int prev_dist = 0;
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();
        prev_dist = node.first;
        for (auto adj : graph[node.second])
        {
            if (distance[adj.first] > prev_dist + adj.second)
            {
                distance[adj.first] = prev_dist + adj.second;
                pq.push({distance[adj.first], adj.first});
            }
        }
    }
    return distance;
}

int main()
{
    vector<vector<pair<int, int>>> graph = {{{1, 4}, {2, 4}},
                                            {{0, 4}, {2, 2}},
                                            {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
                                            {{2, 3}, {5, 2}},
                                            {{2, 1}, {5, 3}},
                                            {{2, 6}, {3, 2}, {4, 3}}};
    vector<int> distance = dijkstra(graph, 0);
    for (auto i : distance)
        cout << i << " ";
}