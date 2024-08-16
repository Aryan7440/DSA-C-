#include <bits/stdc++.h>
using namespace std;
// 1697
//dsu
vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
{
    vector<vector<int>> adj(n, vector<int>(n, 1e9));
    for (auto i : edgeList)
    {
        adj[i[0]][i[1]] = min(i[2], adj[i[0]][i[1]]);
        adj[i[1]][i[0]] = min(i[2], adj[i[1]][i[0]]);
    }
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = max(adj[i][j], max(adj[i][via] , adj[via][j]));
            }
        }
    }
    vector<bool> ans;
    for (auto i : queries)
    {
        if (adj[i[0]][i[1]] < i[2])
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> edgeList = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}}, queries = {{0,4,14},{1,4,13}};
    vector<bool> ans=distanceLimitedPathsExist(n,edgeList,queries);
    for(auto i:ans)cout<<i<<" ";
}