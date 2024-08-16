#include <bits/stdc++.h>
using namespace std;

class DS
{
public:
    unordered_map<int, int> par, size;
    int parent(int x)
    {
        if (par.find(x) == par.end())
        {
            size[x] = 1;
            par[x] = x;
        }
        if (par[x] == x)
            return x;
        
        return parent(par[x]);
    }
    void join(int x, int y)
    {
        int px = parent(x);
        int py = parent(y);
        if (px != py)
        {
            if (size[px] > size[py])
            {
                par[py] = px;
                size[px] += size[py];
            }
            else
            {
                par[px] = py;
                size[py] += size[px];
            }
        }
    }
};
static bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // return {{}};
        DS* ds=new DS();
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),comp);
        int MST=0;
        unordered_set<int> edge;
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            int d=e[2];

            int pu=ds->parent(u);
            int pv=ds->parent(v);
            if(pu!=pv)
            {
                ds->join(u,v);
                edge.insert(e[3]);
                MST+=d;
            }
        }
        delete ds;
        vector<int> critical;
        vector<int> pseudo_critical;

        

        for(int i=0;i<edges.size();i++)
        {
            int mst=0;
            DS* ds=new DS();
            DS* ds2=new DS();
            int mst2=edges[i][2];
            ds2->join(edges[i][0],edges[i][1]);

            int s1=0,s2=0;

            // unordered_set<int> set;
            for(int e=0;e<edges.size();e++)
            {
                // if(i==e)continue;
                int u=edges[e][0];
                int v=edges[e][1];
                int d=edges[e][2];

                int pu=ds->parent(u);
                int pv=ds->parent(v);

                if(pu!=pv && i!=e)
                {
                    ds->join(u,v);
                    // set.insert(edges[e][3]);
                    s1=max(s1,ds->size[pu]);
                    s1=max(s1,ds->size[pv]);
                    mst+=d;
                }


                int pu2=ds2->parent(u);
                int pv2=ds2->parent(v);
                if(pu2!=pv2)
                {
                    ds2->join(u,v);
                    // set.insert(edges[e][3]);
                    s2=max(s2,ds2->size[pu2]);
                    s2=max(s2,ds2->size[pv2]);
                    mst2+=d;
                }
                  
            }
            if(mst!=MST )critical.push_back(edges[i][3]);
            else if(mst2==MST)
            {
                // edge.insert(set.begin(),set.end());
                // if(edge.find(edges[i][3])!=edge.end())
                    pseudo_critical.push_back(edges[i][3]);
            } 
        }
        return {critical,pseudo_critical};
    }

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
    // int n = 5;
    // vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    vector<vector<int>> ans=findCriticalAndPseudoCriticalEdges(n,edges);
    for(auto i:ans)
    {
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }

}