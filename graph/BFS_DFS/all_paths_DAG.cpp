#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, vector<int> &ds, vector<vector<int>> &ans, int node)
{
    ds.push_back(node);
    if (node == graph.size() - 1)
    {
        ans.push_back(ds);
        return;
    }
    for (auto i : graph[node])
    {
        dfs(graph, ds, ans, i);
        ds.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<int> pathvis(graph.size(), 0);
    vector<int> ds;
    vector<vector<int>> ans;
    dfs(graph, ds, ans, 0);
    return ans;
}

int main()
{
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> ans=allPathsSourceTarget(graph);
    for(auto i: ans)
    {
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
}