#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    unordered_map<int, int> parent, size;
    DSU() {}
    int find(int x)
    {
        if (parent.find(x) == parent.end())
        {
            size[x]++;
            parent[x] = x;
        }
        if (parent[x] != x)
        {
            return parent[x] = find(parent[x]);
        }
        
        return x;
    }
    void join(int x, int y)
    {
        int x_par = find(x);
        int y_par = find(y);
        if (x_par != y_par)
        {
            if (size[x_par] > size[y_par])
            {
                parent[y_par] = x_par;
                size[x_par] += size[y_par];
            }
            else
            {
                parent[x_par] = y_par;
                size[y_par] += size[x_par];
            }
        }
    }
};

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    DSU *dsu = new DSU();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j])
            {
                dsu->join(i, j);
            }
        }
    }
    int provinces = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsu->find(i) == i)
            provinces++;
    }
    return provinces;
}
int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected);
}
