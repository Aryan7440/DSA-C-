#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> distance(V, INT_MAX);
    set<pair<int, int>> s;

    distance[S] = 0;
    s.insert({S, 0}); // source

    while (!s.empty())
    {
        pair<int, int> node = *s.begin();
        s.erase(s.begin());
        for (auto adj_ : adj[node.first])
        {
            if (distance[adj_[0]] > node.second + adj_[1])
            {
                distance[adj_[0]] = node.second + adj_[1];
                s.insert({adj_[0], distance[adj_[0]]});
            }
        }
    }
    return distance;
}

int main()
{
    vector<vector<int>> adj[] = {{{1, 4}, {2, 4}},
                               {{0, 4}, {2, 2}},
                               {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
                               {{2, 3}, {5, 2}},
                               {{2, 1}, {5, 3}},
                               {{2, 6}, {3, 2}, {4, 3}}};
    vector<int> distance = dijkstra(6, adj, 0);
    for (auto i : distance)
        cout << i << " ";
}