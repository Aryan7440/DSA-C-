#include <bits/stdc++.h>
using namespace std;
int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        if (manager[i] == -1)
            continue;
        adj[manager[i]].push_back(i);
    }
    queue<int> q;
    q.push(headID);
    int ans = 0;
    while (!q.empty())
    {
        int s = q.size();
        // ans+=informTime[]
        for (int i = 0; i < s; i++)
        {
            int node = q.front();
            ans += informTime[node];
            q.pop();
            for (auto i : adj[node])
            {
                q.push(i);
            }
        }
    }
    return ans;
}