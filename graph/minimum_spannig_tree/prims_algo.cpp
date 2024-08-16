#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prims(vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {-1, 0}}); //(weight,parent,child)
    vector<pair<int, int>> mst;
    vector<int> vis(n, 0);
    vis[0] = 1;
    vector<int> dist(n, 0);

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second.first;
        int v = top.second.second;
        if (!vis[v])
        {
            mst.push_back({u, v});
            dist[v] = d;
            vis[v] = 1;
        }

        for (auto i : adj[v]) // u->v
        {
            int dis = i.second;
            int node = i.first;
            if (!vis[i.first])
            {
                pq.push({dis, {v, node}});
            }
        }
    }
    return mst;
}

int main()
{
    vector<vector<pair<int, int>>> adj = {{{1, 2}, {2, 1}},
                                          {{0, 2}, {2, 1}},
                                          {{0, 1}, {1, 1}, {4, 2}, {3, 2}},
                                          {{2, 2}, {4, 1}},
                                          {{2, 2}, {3, 1}}};
    vector<pair<int, int>> mst = prims(adj);
    for (auto i : mst)
        cout << i.first << " " << i.second << endl;
}