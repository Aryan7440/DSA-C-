#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    set<pair<int, int>> set;
    vector<int> distance(n + 1, INT_MAX);
    vector<int> path(n + 1, 0);
    distance[1] = 0;
    path[1] = 1;
    set.insert({0, 1});
    while (!set.empty())
    {
        pair<int, int> node = *(set.begin());
        set.erase(set.begin());
        for (auto surr : adj[node.second])
        {
            if (distance[surr.first] > node.first + surr.second)
            {
                distance[surr.first] = node.first + surr.second;
                path[surr.first] = node.second;
                set.insert({distance[surr.first], surr.first});
            }
        }
    }
    vector<int> ans;
    if (distance[n] == INT_MAX)
        return {-1};
    int node = n;
    while (path[node] != node)
    {
        ans.push_back(node);
        node = path[node];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{1, 5, 12},
                                 {2, 4, 140},
                                 {2, 10, 149},
                                 {3, 6, 154},
                                 {3, 7, 9},
                                 {3, 8, 226},
                                 {3, 10, 132},
                                 {4, 10, 55},
                                 {5, 8, 33},
                                 {7, 8, 173}};
    // vector<vector<int>> edges={{1,2,2}, {2,5,5}, {2,3,4},{1,4,1},{4,3,3},{3,5,1}};
    vector<int> ans = shortestPath(10, 10, edges);
    for (auto i : ans)
        cout << i << " ";

    // for(int i=0;i<6;i++)
    // {
    //     cout<<i<<" ";
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         cout<<"{"<<adj[i][j].first<<","<<adj[i][j].second<<"}  ,";
    //     }
    //     cout<<endl;
    // }
}