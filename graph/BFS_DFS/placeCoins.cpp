#include <bits/stdc++.h>
using namespace std;

vector<long long> dfs(vector<vector<int>> adj, vector<int> &cost, int node, vector<long long> &ans)
{
    if (adj[node].size() == 0)
    {
        ans[node] = 1;
        return {cost[node]};
    }

    vector<long long> res = {cost[node]};
    for (auto nb : adj[node])
    {
        vector<long long> temp = dfs(adj, cost, nb, ans);
        res.insert(res.end(), temp.begin(), temp.end());
    }
    sort(res.begin(), res.end());
    int N = res.size();
    ans[node] = max(res[N - 1] * res[N - 2] * res[N - 3], res[0] * res[1] * res[N - 1]);
    ans[node] = max(0LL, ans[node]);
    return {res[N - 1], res[N - 2], res[N - 3], res[0], res[1]};
}
vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost)
{
    vector<long long> ans(cost.size());
    vector<vector<int>> adj(cost.size());
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }
    dfs(adj, cost, 0, ans);
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
    vector<int> cost = {1, 2, 3, 4, 5, 6};
    vector<long long> res = placedCoins(edges, cost);
    for (auto x : res)
    {
        cout << x << " ";
    }

    return 0;
}
