#include <bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto i : times)
    {
        adj[i[0]].push_back({i[1], i[2]});
    }

    vector<int> distance(n + 1, INT_MAX);
    queue<pair<int, int>> q;
    q.push({0, k});
    distance[k] = 0;
    int ans = 0;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int s = temp.second;
        int w = temp.first;
        for (auto i : adj[s])
        {
            if (distance[i.first] > w + i.second)
            {
                distance[i.first] = w + i.second;
                q.push({w + i.second, i.first});
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        ans=max(distance[i],ans);
    }
    return ans==INT_MAX?-1:ans;
}

int main()
{
    vector<vector<int>> times={{1,2,1},{2,3,2},{1,3,1}};
    cout<<networkDelayTime(times,3,2);
}