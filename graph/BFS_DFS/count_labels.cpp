#include <bits/stdc++.h>
using namespace std;
vector<int> dfs(int n, vector<vector<int>> &adj, string labels, vector<int> &mp, int x, vector<int> &ans)
{
    vector<int> temp(26, 0);
    for (auto i : adj[x])
    {
        vector<int> t(26, 0);
        t = dfs(n, adj, labels, t, i, ans);
        for (int j = 0; j < 26; j++)
        {
            temp[j] += t[j];
        }
    }
    temp[labels[x] - 'a']++;
    ans[x] = temp[labels[x] - 'a'];
    return temp;
}
vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    vector<int> ans(n, 0);
    vector<int> mp(26, 0);
    vector<vector<int>> adj(n);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
    }
    dfs(n, adj, labels, mp, 0, ans);
    return ans;
}
int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    string labels = "aaabaaa";
    // vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    // string labels = "abaedcd";
    vector<int> ans = countSubTrees(n, edges, labels);
    for (auto i : ans)
        cout << i << " ";
}