#include <bits/stdc++.h>
using namespace std;

long long diameter(vector<vector<long long>> &adj, long long node, long long &ans, int par)
{
    long long res = 0;
    long long d = 0;
    for (auto i : adj[node])
    {
        if (i == par)
            continue;
        long long temp = diameter(adj, i, ans, node);
        d = max(d, res + temp);
        res = max(res, temp);
    }
    ans = max(ans, d);
    return res + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n;
    m = n - 1;
    vector<vector<long long>> adj(n + 1);
    vector<long long> indegee(n + 1, 0);
    for (long long i = 0; i < m; i++)
    {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegee[v]++;
    }
    int root = 0;
    for (long long i = 1; i <= n; i++)
    {
        if (indegee[i] == 0)
        {
            root = i;
            break;
        }
    }
    long long ans = 0;
    diameter(adj, root, ans, -1);
    cout << ans << endl;
}