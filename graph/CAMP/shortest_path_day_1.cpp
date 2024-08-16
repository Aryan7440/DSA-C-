#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int source, vector<vector<int>> &adj)
{
    vector<int> dist(adj.size(), -1);
    int d = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int node = q.front();
            q.pop();
            dist[node] = d;
            for (int j = 0; j < adj[node].size(); j++)
            {
                if (dist[adj[node][j]] == -1)
                    q.push(adj[node][j]);
            }
        }
        d++;
    }
    return dist;
}
int main()
{
    vector<vector<int>> adj = {{1, 2, 3}, {0}, {0, 4}, {0}, {2}};
    vector<int> ans = BFS(4, adj);
    for (auto i : ans)
        cout << i << " ";
}