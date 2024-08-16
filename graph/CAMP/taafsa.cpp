#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> army(n + 1, 0);
    vector<int> vis(n + 1, -1);
    queue<int> q;
    vector<int> blue;
    for (int i = 1; i <= n; i++)
    {
        cin >> army[i];
        if (army[i] == 1)
        {
            vis[i] = 0;
            q.push(i);
        }
        else if (army[i] == 2)
            blue.push_back(i);
        // else if(army[i]==2)
        // {
        //   vis[i]=2;
        //   q.push(i);
        // }
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // int dist=0;
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            int u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (vis[v] == -1)
                {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    double ans = INT_MAX;
    for (auto i : blue)
    {
        int dist = vis[i];
        if (dist == -1)
            continue;
        if (dist % 2 == 0)
            ans = min(ans, (double)dist / 2);
        else
            ans = min(ans, (dist / 2) + 0.5);
    }
    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans;

    return 0;
}