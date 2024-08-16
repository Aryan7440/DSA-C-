#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>>
        adj(n);
    vector<int> indegree(n), Xor(n);
    for (int i = 0; i < n; i++)
    {
        cin >> indegree[i];
        cin >> Xor[i];
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 1)
        {
            q.push(i);
        }
    }
    vector<pair<int, int>> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        indegree[node] = 0;
        int v = Xor[node];
        ans.push_back({node, v});
        indegree[v]--;
        Xor[v] = Xor[v] ^ node;
        if (indegree[v] == 1)
            q.push(v);
    }
    set<pair<int, int>> unique_pairs;
    for (auto &p : ans)
    {
        if (p.first > p.second)
        {
            swap(p.first, p.second);
        }
        unique_pairs.insert(p);
    }
    cout << unique_pairs.size() << endl;
    for (const auto &p : unique_pairs)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}