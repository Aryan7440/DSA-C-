#include <bits/stdc++.h>
using namespace std;

// vector<int> bfsOfGraph( vector<vector<int>> adj)//for adjacency list
// {
//     // Code here
//     queue<int> q;
//     vector<int> ans;
//     vector<int> visited(adj.size(), 0);
//     q.push(0);
//     visited[0] = 1;
//     while (!q.empty())
//     {
//         int top = q.front();
//         q.pop();

//         ans.push_back(top);
//         for (auto i : adj[top])
//         {
//             if (!visited[i])
//             {
//                 q.push(i);
//                 visited[i] = 1;
//             }
//         }
//     }
//     return ans;
// }
vector<int> bfsOfGraph( vector<vector<int>> adj)//for adjacency matrix
{
    // Code here
    queue<int> q;
    vector<int> ans;
    vector<int> visited(adj.size(), 0);
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        ans.push_back(top);
        for(int i=0;i<adj[top].size();i++)
        {
            if(adj[top][i]==1 && !visited[i])
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> adj={{1,2,3},{0},{0,4},{0},{2}};
    vector<vector<int>> mat = {{0, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}};
    vector<int> ans=bfsOfGraph(mat);
    // vector<int> ans=bfsOfGraph(adj);
    for(auto i: ans)cout<<i<<" ";
}