#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(vector<vector<int>> &graph, int src)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(src);
    int d = 0;
    dist[src]=0;
    while (!q.empty())
    {
        int s = q.size();
        d++;
        for (int i = 0; i < s; i++)
        {
            int node = q.front();
            q.pop();
            for (auto i : graph[node])
            {
                if (dist[i] > d)
                {
                    dist[i] = d;
                    q.push(i);
                }
            }
        }
    }
    return dist;
}

int main()
{
    vector<vector<int>> graph = {{1, 3},
                                 {0, 2, 3},
                                 {1, 6},
                                 {0, 4},
                                 {3, 5},
                                 {4, 6},
                                 {2, 5, 7, 8},
                                 {6, 8},
                                 {6, 7}};
    vector<int> distance=shortest_path(graph,0);
    for(auto i: distance)cout<<i<<" ";
}