#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    return 0;
}
