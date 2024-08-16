#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> mp1;
    unordered_map<int, string> mp2;
    vector<vector<int>> adj(n);
    unordered_map<int, unordered_map<int, string>> mp;
    int mn = 0;
    for (int i = 0; i < m; i++)
    {
        string u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;
        if (mp1.find(u) == mp1.end())
        {
            mp1[u] = mn;
            mp2[mn] = u;
            mn++;
        }
        if (mp1.find(v) == mp1.end())
        {
            mp1[v] = mn;
            mp2[mn] = v;
            mn++;
        }
        mp[mp1[u]][mp1[v]] = w;
        adj[mp1[u]].push_back(mp1[v]);
    }
    string s, t;
    cin >> s >> t;

    vector<int> parent(n, -1);
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(mp1[s]);
    vis[mp1[s]] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = 1;
                parent[u] = v;
                q.push(u);
            }
        }
    }
    if (!vis[mp1[t]])
    {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<int> path;
    for (int i = mp1[t]; i != mp1[s]; i = parent[i])
    {
        path.push_back(i);
    }
    path.push_back(mp1[s]);
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << endl;
    for (int i = 0; i < path.size() - 1; i++)
    {
        cout << mp[path[i]][path[i + 1]] << endl;
    }
    return 0;
}