#include <bits/stdc++.h>
using namespace std;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto i : redEdges)
    {
        adj[i[0]].push_back({i[1], 1});
    }
    for (auto i : blueEdges)
    {
        adj[i[0]].push_back({i[1], 0});
    }
    vector<int> dist(n, -1);
    int d = 0;
    queue<pair<int, int>> q;
    q.push({0, -1});
    dist[0] = 0;
    while (!q.empty())
    {
        int s = q.size();
        d++;
        for (int i = 0; i < s; i++)
        {
            int node = q.front().first;
            int edge = q.front().second;
            q.pop();
            for(int j=0;j<adj[node].size();j++)
            {
                int sur=adj[node][j].first;
                int col=adj[node][j].second;
                if(col!=edge && sur!=-1)
                {
                    q.push({sur,col});
                    if(dist[sur]==-1)dist[sur]=d;
                    adj[node][j].first=-1;
                }
            }
        }
    }
    return dist;
}

int main()
{
    int n = 3;
    vector<vector<int>> redEdges = {{0, 1}, {0, 2}}, blueEdges = {{1, 0}};
    vector<int> ans = shortestAlternatingPaths(n, redEdges, blueEdges);
    for (auto i : ans)
        cout << i << " ";
    //  [0,1,-1]
}