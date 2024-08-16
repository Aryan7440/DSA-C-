#include <bits/stdc++.h>
using namespace std;

class disjoint_set
{
    vector<int> rank, parent;

public:
    disjoint_set(int n)
    {
        rank.resize(n + 1, 0);
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
    void union_byrank(int u, int v)
    {
        int up = find_parent(u);
        int vp = find_parent(v);
        if (up == vp)
            return;
        if (rank[up] > rank[vp])
        {
            parent[vp] = up;
        }
        else if (rank[up] < rank[vp])
        {
            parent[up] = vp;
        }
        else
        {
            parent[up] = vp;
            rank[vp]++;
        }
    }
};
int main()
{
    disjoint_set a(7);
    a.union_byrank(1,2);
    a.union_byrank(2,3);
    a.union_byrank(4,5);
    a.union_byrank(6,7);
    a.union_byrank(5,6);
    if(a.find_parent(3)==a.find_parent(7))cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    a.union_byrank(1,6);
    if(a.find_parent(3)==a.find_parent(7))cout<<"same"<<endl;
    else cout<<"not same"<<endl;


}