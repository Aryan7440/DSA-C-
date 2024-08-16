#include<bits/stdc++.h>
using namespace std;
class disjoint_set
{
    vector<int> size, parent;

public:
    disjoint_set(int n)
    {
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }

    int find_parent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find_parent(parent[u]);
    }
    void union_bysize(int u, int v)
    {
        int up = find_parent(u);
        int vp = find_parent(v);
        if (up == vp)
            return;
        if (size[up] > size[vp])
        {
            parent[vp] = up;
            size[up]+=size[vp];
        }
        else
        {
            parent[up] = vp;
            size[vp]+=size[up];
        }
    }
};
vector<pair<int,int>> kruskal(vector<vector<int>> &edges)
{
    int n=edges.size();
    sort(edges.begin(),edges.end());
    disjoint_set set(n);
    vector<pair<int,int>> mst;
    int distance=0;
    for(auto i:edges)
    {
        int dist=i[0];
        int u=i[1];
        int v=i[2];
        
        int pu=set.find_parent(u);
        int pv=set.find_parent(v);
        if(pu!=pv)
        {
            mst.push_back({u,v});
            set.union_bysize(u,v);
            distance+=dist;
        }
    }
    return mst;
}
int main()
{
    vector<vector<int>> edges={{1,0,1},{1,1,2},{1,0,2},{4,2,3},{2,3,4},{2,3,5},{2,4,5}};
    // vector<vector<int>> edges={{9,4,5},{8,3,6},{7,2,6},{5,3,4},{4,1,5},{3,2,4},{3,2,3},{2,1,2},{1,1,4}};
    vector<pair<int,int>> mst=kruskal(edges);
    for(auto i:mst)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}