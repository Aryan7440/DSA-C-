#include <bits/stdc++.h>
using namespace std;
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    priority_queue<pair<double, int>> pq;
    vector<int> vis(n, 0);
    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
        graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    pq.push({1, start});
    while (!pq.empty())
    {
        pair<double, int> p = pq.top();
        pq.pop();

        double prob = p.first;
        int node = p.second;
        vis[node]=1;
        if(node==end)return prob;
        for (auto i : graph[node])
        {
            if (!vis[i.first])
            {
                pq.push({prob * i.second, i.first});
            }
        }
    }
    return 0;
}
int main()
{
    int n = 3, start = 0, end = 2;
    vector<vector<int>>edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    cout<<maxProbability(n,edges,succProb,start,end);
}