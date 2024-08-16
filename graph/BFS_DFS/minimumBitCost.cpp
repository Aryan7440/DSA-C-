#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &adj, int node, int col, vector<int> &vis, int &bit)
{
    for (auto child : adj[node])
    {
        if (bit == -1)
            bit = child.second;
        else
            bit = bit & child.second;
    }
    for (auto child : adj[node])
    {

        if (!vis[child.first])
        {
            vis[child.first] = col;
            dfs(adj, child.first, col, vis, bit);
        }
    }
}
vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto edge : edges)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<int> vis(n, 0);
    int col = 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = col;
            int bit = -1;
            dfs(adj, i, col, vis, bit);
            mp[col] = bit;
            col++;
        }
    }
    vector<int> ans;
    for (auto q : query)
    {
        if (vis[q[0]] == vis[q[1]])
        {
            if (mp[vis[q[0]]] == -1)
                ans.push_back(-1);
            else
                ans.push_back(mp[vis[q[0]]]);
        }
        else
            ans.push_back(-1);
    }
    return ans;
}
int main()
{
    // int n = 5;
    // vector<vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}};
    // vector<vector<int>> query = {{0, 3}, {3, 4}};
    int n = 3;
    vector<vector<int>> edges = {{0, 2, 7}, {0, 1, 15}, {1, 2, 6}, {1, 2, 1}}, query = {{1, 2}};
    vector<int> ans = minimumCost(n, edges, query);
    for (auto it : ans)
        cout << it << " ";
}