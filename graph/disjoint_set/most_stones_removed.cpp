#include <bits/stdc++.h>
// #include "disjoint_set.h"
using namespace std;
// struct hashFunction
// {
//     size_t operator()(const pair<int, int> &x) const
//     {
//         return x.first ^ x.second;
//     }
// };
// int removeStones(vector<vector<int>> &stones)
// {
//     int n = stones.size();
//     unordered_map<int, vector<int>> rows;
//     unordered_map<int, vector<int>> cols;
//     unordered_set<pair<int, int>, hashFunction> set;
//     for (auto i : stones)
//     {
//         rows[i[0]].push_back(i[1]);
//         cols[i[1]].push_back(i[0]);
//     }
//     queue<pair<int, int>> q;
//     int count = 0;
//     for (auto j : stones)
//     {
//         if (set.find({j[0], j[1]}) == set.end())
//         {
//             count++;
//             q.push({j[0], j[1]});
//             set.insert({j[0], j[1]});
//             while (!q.empty())
//             {
//                 auto p = q.front();
//                 int x = p.first;
//                 int y = p.second;
//                 q.pop();
//                 for (auto i : rows[x])
//                 {
//                     if (set.find({x, i}) == set.end())
//                     {
//                         set.insert({x, i});
//                         q.push({x, i});
//                     }
//                 }
//                 for (auto i : cols[y])
//                 {
//                     if (set.find({i, y}) == set.end())
//                     {
//                         set.insert({i, y});
//                         q.push({i, y});
//                     }
//                 }
//             }
//         }
//     }
//     return n - count;
// }
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
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    DSU a;
    for (auto i : stones)
    {
        a.join(i[0], i[1] + 1e5);
    }
    return n-a.count;
}

int main()
{
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

    cout << removeStones(stones);
}
