#include <bits/stdc++.h>
using namespace std;
class DS
{
public:
    unordered_map<int, int> parent, size;
    int find_parent(int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            size[x]++;
        }
        if (parent[x] != x)
        {
            return parent[x] = find_parent(parent[x]);
        }
        return x;
    }
    void join(int x, int y)
    {
        int px = find_parent(x);
        int py = find_parent(y);

        if (px == py)
            return;
        else
        {
            if (size[px] > size[py])
            {
                parent[py] = px;
                size[py] += size[x];
            }
            else
            {
                parent[px] = py;
                size[px] += size[py];
            }
        }
    }
};
int minScore(int n, vector<vector<int>> &roads)
{
    DS set;
    set.find_parent(1);
    int ans=INT_MAX;
    for(int i=0;i<roads.size();i++)
    {
        set.join(roads[i][0],roads[i][1]);
    }
    for(int i=0;i<roads.size();i++)
    {
        if(set.find_parent(roads[i][1])==set.find_parent(1))ans=min(ans,roads[i][2]);
        if(set.find_parent(roads[i][0])==set.find_parent(1))ans=min(ans,roads[i][2]);
    }
    return ans;
}
int main()
{
    int n = 4;
    vector<vector<int>>roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    cout<<minScore(n,roads);
}