#include <bits/stdc++.h>
using namespace std;
int largestPathValue(string colors, vector<vector<int>> &edges)
{
    int n = colors.size();
    int m = edges.size();
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    for (auto i : edges)
    {
        indegree[i[1]]++;
        adj[i[0]].push_back(i[1]);
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<vector<int>> dp(n, vector<int>(26, 0)); //(node,color)
    int vis = 0, max_count = 0;
    while (!q.empty())
    {
        vis++;
        int u = q.front();
        q.pop();
        for (auto v : edges[u])
        {
            for (int c = 0; c < 26; c++)
            {
                int col = ((colors[v] - 'a') == c) ? 1 : 0;
                dp[v][c] = max(dp[v][c], dp[u][c] + col);
            }
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
        for (int i = 0; i < 26; i++)
            max_count = max(max_count, dp[u][i]);
    }
    return vis == n ? max_count : -1;
}
int main()
{
    vector<vector<int>> edges={{0,1},{0,2},{2,3},{3,4}};
    string colour="abaca";
    cout<<largestPathValue(colour,edges);

}