#include <bits/stdc++.h>
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
int main()
{
    disjoint_set a(7);
    a.union_bysize(1,2);
    a.union_bysize(2,3);
    a.union_bysize(3,4);
    a.union_bysize(5,6);
    a.union_bysize(6,7);
    if(a.find_parent(6)==a.find_parent(1))cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    a.union_bysize(1,7);
    if(a.find_parent(6)==a.find_parent(1))cout<<"same"<<endl;
    else cout<<"not same"<<endl;

    


}