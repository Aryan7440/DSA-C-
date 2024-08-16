#include <bits/stdc++.h>
using namespace std;

bool check(bool graph[101][101], vector<int> &vis, int node, int colour, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && graph[node][i] == 1)
        {
            if (vis[i] == colour)
                return false;
        }
    }
    return true;
}

bool dfs(bool graph[101][101], vector<int> &vis, int node, int m, int n)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (check(graph, vis, node, i, n))
        {
            vis[node] = i;
            if (dfs(graph, vis, node + 1, m, n))
                return true;
            vis[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> vis(n, 0);

    if (dfs(graph, vis, 0, m, n))
        return true;
    return false;
}