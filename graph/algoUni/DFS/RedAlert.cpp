#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int dfs(vector<vector<int>> &adj, vector<int> &col, int node, int cur, int c)
{
    if (col[node])
        cur++;
    else
        cur = 0;
    if (cur > c)
        return 0;
    if (adj[node].size() == 0)
        return 1;
    int sum = 0;
    for (auto i : adj[node])
    {
        sum += dfs(adj, col, i, cur, c);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    vector<vector<int>> adj(n + 1);
    vector<int> col(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << dfs(adj, col, 1, 0, c) << endl;
    return 0;
}
