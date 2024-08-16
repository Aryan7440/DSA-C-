// strongly connected components
#include <bits/stdc++.h>
using namespace std;
void dfs1(int V, vector<int> adj[], int x, vector<int> &vis, vector<int> &s)
{
    vis[x] = 1;
    for (auto i : adj[x])
    {
        if (!vis[i])
            dfs1(V, adj, i, vis, s);
    }
    s.push_back(x);
}
void dfs3(int V, vector<int> adjR[], int x, vector<int> &vis)
{
    vis[x] = 1;
    for (auto i : adjR[x])
    {
        if (!vis[i])
            dfs3(V, adjR, i, vis);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs1(V, adj, i, vis, s);
    }
    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i] << " ";
    cout << endl;
    // reverse
    vector<int> adjR[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto j : adj[i])
        {
            adjR[j].push_back(i);
        }
    }

    int count = 0;
    while (!s.empty())
    {
        if (!vis[s.back()])
        {
            count++;
            dfs3(V, adjR, s.back(), vis);
        }
        s.pop_back();
    }
    return count;
}

int main()
{
    vector<int> adj[5] = {{2, 3}, {0}, {1}, {4}, {}};
    cout << kosaraju(5, adj);
}