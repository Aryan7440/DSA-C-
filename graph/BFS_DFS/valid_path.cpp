#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    if (source == destination)
        return true;
    vector<vector<int>> adj(n);
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto i : adj[temp])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
                if (i == destination)
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> edges={{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};
    cout<<validPath(10,edges,5,9);
}