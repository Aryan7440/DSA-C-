#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int s)
{
    vector<int> distance(V, INT_MAX);
    distance[s]=0;
    for (int j = 0; j < V - 1; j++)
    {
        int flag = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int dist = edges[i][2];
            if (distance[v] > distance[u] + dist)
            {
                distance[v] = distance[u] + dist;
                flag = 1;
            }
        }
        if(!flag)break;
    }
    // check negative cycle

    for(auto i:edges)
    {
        int u=i[0];
        int v=i[1];
        int d=i[2];
        if(distance[v]!=INT_MAX && distance[v]>distance[u]+d)return {0};
    }
    return distance;
}