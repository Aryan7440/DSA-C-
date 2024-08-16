#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void minimumSpanningTree(vector<vector<pair<long long, long long>>> &adj)
{
    long long n = adj.size();
    vector<long long> vis(n, 0);
    vector<long long> key(n, -1);
    vector<long long> parent(n, -1);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 1});
    long long mst = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        long long u = top.second;
        if (vis[u])
            continue;
        vis[u] = 1;
        mst += top.first;
        for (auto i : adj[u])
        {
            long long v = i.first;
            long long w = i.second;
            if (!vis[v] && (key[v] == -1 || w < key[v]))
            {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
    cout << mst << endl;
    // for (long long i = 1; i < n; i++)
    // {
    //     cout << parent[i] << " " << i << endl;
    // }
    // for (long long i = 1; i < n; i++)
    // {
    //     cout << key[i] << " " << i << endl;
    // }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    minimumSpanningTree(adj);

    return 0;
}
