#include <bits/stdc++.h>
using namespace std;
class circle
{
public:
    long long x, y, r;
};
long long dist(circle a, circle b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
vector<long long> bfs(vector<vector<long long>> &adj, long long src)
{
    long long n = adj.size();
    vector<long long> vis(n, 0);
    queue<long long> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        long long v = q.front();
        q.pop();
        for (long long u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    return vis;
}
void solve()
{
    long long X, Y;
    cin >> X >> Y;

    long long n;
    cin >> n;

    vector<vector<long long>> adj(n + 4);

    vector<circle> cir;
    for (long long i = 0; i < n; i++)
    {
        circle c;
        cin >> c.x >> c.y >> c.r;
        cir.push_back(c);
    }
    for (long long i = 0; i < n; i++)
    {
        if (cir[i].y + cir[i].r >= Y && cir[i].y - cir[i].r <= Y)
        {
            adj[0].push_back(i + 4);
            adj[i + 4].push_back(0);
        }
        if (cir[i].x + cir[i].r >= X && cir[i].x - cir[i].r <= X)
        {
            adj[1].push_back(i + 4);
            adj[i + 4].push_back(1);
        }
        if (cir[i].y - cir[i].r <= 0 && cir[i].y + cir[i].r >= 0)
        {
            adj[2].push_back(i + 4);
            adj[i + 4].push_back(2);
        }
        if (cir[i].x - cir[i].r <= 0 && cir[i].x + cir[i].r >= 0)
        {
            adj[3].push_back(i + 4);
            adj[i + 4].push_back(3);
        }
    }
    for (long long i = 0; i < n; i++)
    {
        for (long long j = i + 1; j < n; j++)
        {
            if (dist(cir[i], cir[j]) <= (cir[i].r + cir[j].r) * (cir[i].r + cir[j].r))
            {
                adj[i + 4].push_back(j + 4);
                adj[j + 4].push_back(i + 4);
            }
        }
    }
    vector<long long> vis0 = bfs(adj, 0);
    vector<long long> vis1 = bfs(adj, 1);

    if (vis0[3] || vis0[2] || vis1[2] || vis1[3])
        cout << "No\n";
    else
        cout << "Yes\n";
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
        solve();
}