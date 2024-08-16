#include <bits/stdc++.h>
using namespace std;

bool UTIL(int s, vector<int> adj[], vector<int> &visited)
{
    queue<pair<int, int>> q;
    visited[s] = 1;
    q.push({s, -1});

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (auto i : adj[temp.first])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push({i, temp.first});
            }
            else if (temp.second != i)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> visited(V, 0);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(UTIL(i,adj,visited))return true;
        }
    }
    return false;
}

int main()
{
    vector<int> adj[]={{},{2},{1,3},{2}};
    cout<<isCycle(4,adj);
}