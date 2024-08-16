#include <bits/stdc++.h>
using namespace std;

int shortestPathLength(vector<vector<int>> &graph)
{
    int n = graph.size();
    if(n==0)return 0;
    int last = (1 << n) - 1 ;// 1111
    queue<pair<int,int>> q;// node,mask
    set<pair<int,int>> s;

    for(int i=0;i<n;i++)
    {
        q.push({i,1<<i});
        s.insert({i,1<<i});
    }

    int dist=0;
    while(!q.empty())
    {
        int si=q.size();
        dist++;
        for(int i=0;i<si;i++)
        {
            auto p=q.front();
            q.pop();
            int node=p.first;
            int mask=p.second;
            if(mask==last)return dist;
            for(auto j:graph[node])
            {
                if(s.find({j,mask|1<<j})==s.end())
                {
                    s.insert({j,mask|1<<j});
                    q.push({j,mask|1<<j});
                }
            }

        }
    }
    return -1;
}