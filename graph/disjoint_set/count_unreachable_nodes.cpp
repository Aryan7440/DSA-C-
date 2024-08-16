#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    unordered_map<int, int> parent, size;
    int par(int x)
    {
        if (parent.find(x) == parent.end())
        {
            size[x]++;
            return parent[x] = x;
        }
        if (parent[x] != x)
        {
            return parent[x] = par(parent[x]);
        }
        return x;
    }
    void join(int x, int y)
    {
        int px = par(x);
        int py = par(y);
        if (px == py)
            return;
        else
        {
            if (size[px] > size[py])
            {
                parent[py] = px;
                size[px] += size[py];
            }
            else
            {
                parent[px] = py;
                size[py] += size[px];
            }
        }
    }
};
long long countPairs(int n, vector<vector<int>> &edges)
{
    DSU dsu;
    for (auto it : edges)
    {
        dsu.join(it[0], it[1]);
    }
    vector<int> set;
    for (int i = 0; i < n; i++)
    {
        if (dsu.par(i) == i)
            set.push_back(dsu.size[i]);
    }
    int m = set.size();
    long long int ans = n * (n - 1) / 2;
    for (auto i : set)
        ans -= i * (i - 1) / 2;
    // for (int i = 0; i < m - 1; i++)
    // {
    //     for (int j = i + 1; j < m; j++)
    //     {
    //         ans += set[i] * set[j];
    //     }
    // }
    return ans;
}
int main()
{
    vector<vector<int>> edges = {{0, 1}, {2, 3}, {4, 5}};
    // vector<vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    // cout << countPairs(6, edges);
    int a=100000 * 99999 ;
    long long b=100000 * 99999 ;
    // cout<< a<<endl;
    cout<< b<<endl;
    // cout<<
}