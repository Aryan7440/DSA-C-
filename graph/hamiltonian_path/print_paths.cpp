#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj,vector<int>&vis,int node,vector<int> &path,vector<vector<int>>&paths)
{
    vis[node]=1;
    path.push_back(node);
    if(path.size()==adj.size())
    {
        paths.push_back(path);
        path.pop_back();
        vis[node]=0;
        return;
    }
    for(int i=0;i<adj[node].size();i++)
    {
        if(adj[node][i]  && !vis[i])dfs(adj,vis,i,path,paths);
    }
    path.pop_back();
    vis[node]=0;
    return;
}
vector<vector<int>> Hamiltonian_paths(vector<vector<int>>&adj)
{
    int n=adj.size();
    vector<vector<int>> paths;
    vector<int>vis(n,0);
    vector<int> path;

    for(int i=0;i<n;i++)
    {
        dfs(adj,vis,i,path,paths);
    }
    return paths;
}
int main()
{
    vector<vector<int>> adj=  {{0, 1, 1, 1, 0}, {1, 0, 1, 0, 1}, {1, 1, 0, 1, 1}, {1, 0, 1, 0, 0},{0,1,1,0,0}};
    vector<vector<int>> paths=Hamiltonian_paths(adj);
    for(auto p:paths)
    {
        for(auto i:p)cout<<i<<" ";
        cout<<endl;
    }
}