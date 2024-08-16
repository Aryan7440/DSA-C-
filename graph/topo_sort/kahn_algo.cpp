#include <bits/stdc++.h>
using namespace std;

vector<int> kahns_algo(vector<vector<int>> &adj)
{
    vector<int> indegree(adj.size(),0);
    for (auto i : adj)
    {
        for (auto j : i)
            indegree[j]+=1;
    }

    queue<int> q;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        topo.push_back(q.front());
        q.pop();
        for (auto i : adj[topo.back()])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return topo;
}
int main()
{
    vector<vector<int>> adj={{},{4},{4},{1,2},{}};
    // vector<vector<int>> adj={{},{},{3},{1},{0,1},{2,0}};
    vector<int> ans=kahns_algo(adj);
    reverse(ans.begin(),ans.end());
    ans.clear();
    for(auto i:ans)cout<<i<<" ";
    // cout<<typeof(ans);
}