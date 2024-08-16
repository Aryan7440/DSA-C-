#include <bits/stdc++.h>
using namespace std;
// int closestMeetingNode(vector<int> &edges, int node1, int node2)
// {
//     int n = edges.size();
//     vector<vector<int>> adj(n);
//     for (int i = 0; i < n; i++)
//     {
//         if (edges[i] == -1)
//             continue;
//         adj[edges[i]].push_back(i);
//     }
//     int ans = -1;
//     int min_dist = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         queue<int> q;
//         vector<int> vis(n, 0);
//         vector<int> dis(n, INT_MAX);
//         q.push(i);
//         vis[i] = 1;
//         int dist = 0;
//         dis[i] = 0;
//         while (!q.empty())
//         {
//             int s = q.size();
//             dist++;
//             for (int j = 0; j < s; j++)
//             {
//                 int node = q.front();
//                 q.pop();
//                 for (auto i : adj[node])
//                 {
//                     if (!vis[i])
//                     {
//                         vis[i] = 1;
//                         dis[i] = dist;
//                         if (vis[node1] && vis[node2])
//                             break;
//                         q.push(i);
//                     }
//                 }
//                 if (vis[node1] && vis[node2])
//                     break;
//             }
//             if (vis[node1] && vis[node2])
//                 break;
//         }
//         if (min_dist > max(dis[node1], dis[node2]))
//         {
//             min_dist = max(dis[node1], dis[node2]);
//             ans = i;
//         }
//     }
//     return ans;
// }

vector<int> bfs(vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[src] = 0;
    int d=0;
    q.push(src);
    while (!q.empty())
    {
        int s=q.size();
        d++;
        for(int i=0;i<s;i++)
        {
            int node=q.front();
            q.pop();
            for(auto nb:adj[node])
            {
                if(dist[nb]>d)
                {
                    dist[nb]=d;
                    q.push(nb);
                }
            }
        }
    }
    return dist;
}
int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    int n = edges.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        if (edges[i] == -1)
            continue;
        adj[i].push_back(edges[i]);
    }
    
    vector<int> d1=bfs(adj,node1);
    vector<int> d2=bfs(adj,node2);
    int ans=-1;
    int dist=INT_MAX;

    for(int i=0;i<n;i++)
    {
        int di=max(d1[i],d2[i]);
        if(di<dist)
        {
            dist=di;
            ans=i;
        }
    }
    return ans;
}
int main()
{
    vector<int> edges = {1,2,-1};
    // vector<int> edges = {2,2,3,-1};
    cout<<closestMeetingNode(edges,0,2);
}