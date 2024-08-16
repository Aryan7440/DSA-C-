#include <bits/stdc++.h>
using namespace std;
// bool dfs(vector<vector<int>> &adj, int node,int bitMask,vector<vector<int>>&dp )
// {
//     if(bitMask==1<<node)return true;
//     if(dp[node][bitMask]!=-1)return dp[node][bitMask];
//     int nextMask=bitMask ^ (1<<node);
//     bool res=0;
//     for(int i=0;i<adj[node].size();i++)
//     {
//         if(adj[node][i] && (bitMask & (1<<i)))
//         {
//             res=res|dfs(adj,i,nextMask,dp);
//         }
//     }
//     return dp[node][bitMask]= res;
// }
// bool dfs(vector<vector<int>> &adj, int node,int bitMask )
// {
//     if(bitMask==1<<node)return true;
//     int nextMask=bitMask ^ (1<<node);
//     bool res=0;
//     for(int i=0;i<adj[node].size();i++)
//     {
//         if(adj[node][i] && (bitMask & (1<<i)))
//         {
//             res=res|dfs(adj,i,nextMask);
//         }
//     }
//     return res;
// }

// bool HamiltonianPath(vector<vector<int>> &adj)
// {
//     int ans=0;
//     int n=adj.size();
//     vector<vector<int>>dp(n,vector<int>((1<<n),-1));
//     for(int i=0;i<n;i++)
//     {
//         ans=ans|dfs(adj,i,(1<<n)-1,dp);
//     }
//     return ans;
// }
bool HamiltonianPath(vector<vector<int>> &adj)
{
    int ans=0;
    int n=adj.size();
    vector<vector<int>>dp(n,vector<int>((1<<n),0));
    for(int i=0;i<n;i++)dp[i][1<<i]=1;
    

    // for(int i=0;i<n;i++)
    // {
    //     ans=ans|dfs(adj,i,(1<<n)-1,dp);
    // }
    return ans;
}

int main()
{
    vector<vector<int>> adj = {{0, 1, 1, 1, 0},
                               {1, 0, 1, 0, 1},
                               {1, 1, 0, 1, 1},
                               {1, 0, 1, 0, 0},
                               {0, 1, 1, 0, 0}};
    int N = adj.size();

    if (HamiltonianPath(adj))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}