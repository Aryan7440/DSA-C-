#include <bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> adj(n, vector<int>(n, 1e9));
    for (auto i : edges)
    {
        adj[i[0]][i[1]] = i[2];
        adj[i[1]][i[0]] = i[2];
    }
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
            }
        }
    }
    int citycnt = n;
    int cityno = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] <= distanceThreshold)
            {
                cnt++;
            }
        }
        if (citycnt >= cnt)
        {
            citycnt = cnt;
            cityno = i;
        }
    }
    return cityno;
}