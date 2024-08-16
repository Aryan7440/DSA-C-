#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    for (auto i : prerequisites)
    {
        adj[i[0]].push_back(i[1]);
    }
    vector<int> indegree(numCourses);
    for (auto i : adj)
    {
        for (auto j : i)
            indegree[j]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        topo.push_back(q.front());
        q.pop();
        for(auto i:adj[topo.back()])
        {
            indegree[i]--;
            if(indegree[i]==0)q.push(i);
        }
    }
    return topo.size() == numCourses;
}

int main()
{
    vector<vector<int>> prerequisites ={{1,4},{2,4},{3,1},{3,2}};
    cout<<canFinish(5,prerequisites);
    
}