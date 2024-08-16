#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    unordered_map<int, int> parent, size;
    int count = 0;
    int find(int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            size[x]++;
            count++;
        }
        if (parent[x] != x)
        {
            return parent[x] = find(parent[x]);
        }
    }
    void join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        else
        {
            count--;
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

