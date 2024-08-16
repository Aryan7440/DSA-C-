#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &graph, vector<int> &vis, int node, stack<int>&topo)
{
    vis[node] = 1;

    for (auto i : graph[node])
    {
        if (!vis[i.first])
        {
            dfs(graph, vis, i.first, topo);
        }
    }
    topo.push(node);
}

stack<int> topo_sort(vector<vector<pair<int, int>>> &graph)
{
    stack<int> topo;
    vector<int> vis(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            dfs(graph, vis, i, topo);
        }
    }
    return topo;
}
vector<int> shortest_path(vector<vector<pair<int,int>>> &graph)
{
    stack<int> topo=topo_sort(graph);
    vector<int> dist(graph.size(),INT_MAX);
    dist[topo.top()]=0; //source
    // int prev_dist=0;
    while (!topo.empty())
    {
        int node=topo.top();
        int prev_dist=dist[node];
        topo.pop();
        for(auto i:graph[node])
        {
            if(i.second+prev_dist<dist[i.first])
            {
                dist[i.first]=i.second+prev_dist;
            }
        }
    }
    return dist;  
}
int main()
{
    vector<vector<pair<int, int>>> graph = { {{1, 2}},
                                             {{3, 1}},
                                             {{3, 3}},
                                             {},
                                             {{0, 3}, {2, 1}},
                                             {{4, 1}},
                                             {{4, 2}, {5,3}} };
    vector<int> distance=shortest_path(graph);
    for(auto i:distance)cout<<i<<" ";

    
    
}
