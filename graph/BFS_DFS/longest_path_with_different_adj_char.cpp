#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &adj, string &s, int par, int &mcount, int x)
{
    int temp = 0;
    int max_d = 0;
    for (auto i : adj[x])
    {
        int d = dfs(adj, s, x, mcount, i);
        if (s[x] == s[i])
            continue;
        max_d = max(d, max_d);
        temp += d;
    }
    mcount = max(mcount, temp+1 );
    return 1 + max_d;
}
int longestPath(vector<int> &parent, string s)
{
    int n = s.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].push_back(i);
        // adj[i].push_back(parent[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int mcount = 0;
        dfs(adj, s, -1, mcount, i);
        ans = max(ans, mcount);
    }
    return ans;
}
int main()
{
    // vector<int>parent = {-1,0,0,1,1,2};
    // string s = "abacbe";
    vector<int> parent = {-1, 0, 0, 0};
    string s = "aabc";
    cout << longestPath(parent, s);
}