#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    unordered_map<int, int> parent, size;
    int find(int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            size[x]++;
        }
        if (parent[x] != x)
        {
            return parent[x] = find(parent[x]);
        }
        return x;
    }
    void join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        else
        {
            if (size[px] > size[py])
            {
                parent[py] = px;
                size[py] += size[px];
            }
            else
            {
                parent[px] = py;
                size[px] += size[py];
            }
        }
    }
};
int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> mp;
    int n = vals.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        mp[vals[i]].push_back(i);
    }
    for (auto i : edges)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    sort(vals.begin(), vals.end());
    unordered_set<int> vis;
    DSU dsu;
    int ans=0;
    unordered_set<int> v;
    for (int i = 0; i < n; i++)
    {
        int val = vals[i];
        if(v.find(val)!=v.end())continue;
        v.insert(val);
        for (auto node : mp[val])
        {
            vis.insert(node);
            for (auto p : adj[node])
            {
                if (vis.find(p) != vis.end())
                {
                    dsu.join(p,node);
                }
            }
        }
        unordered_map<int,int>freq;
        
        for (auto node : mp[val])
        {
            freq[dsu.find(node)]++;
            ans+=freq[dsu.find(node)];
        }

    }
    return ans;
}
// 4->4+6;
// 3->3+3
// 2->2+1
int main()
{
    vector<int> vals ={1,3,2,1,3};
    vector<vector<int>>edges={{0,1},{0,2},{2,3},{2,4}};
    cout<<numberOfGoodPaths(vals,edges);

}
