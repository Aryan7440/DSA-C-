#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/evaluate-division/description/
double bfs(unordered_map<string, vector<pair<string, double>>> &mp, string src, string des)
{
    // if(mp.find(src)==mp.end())return -1;
    int n = mp.size();
    unordered_set<string> vis;
    queue<pair<string, double>> q;
    q.push({src, 1});
    vis.insert(src);
    while (!q.empty())
    {
        string node = q.front().first;
        double res = q.front().second;
        q.pop();
        if (node == des)
            return res;

        for (auto next_node : mp[node])
        {
            if (vis.find(next_node.first) == vis.end())
            {
                string next = next_node.first;
                double path = next_node.second;
                q.push({next, path * res});
                vis.insert(next);
            }
        }
    }
    return -1;
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    unordered_map<string, vector<pair<string, double>>> mp;
    for (int i = 0; i < equations.size(); i++)
    {
        mp[equations[i][0]].push_back({equations[i][1], values[i]});
        mp[equations[i][1]].push_back({equations[i][0], (double)1 / values[i]});
    }
    vector<double> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        if (mp.find(queries[i][0]) == mp.end())
        {
            ans.push_back(-1);
            continue;
        }
        double temp = bfs(mp, queries[i][0], queries[i][1]);
        ans.push_back(temp);
        // mp[queries[i][0]].push_back({queries[i][1], temp});
        // mp[queries[i][1]].push_back({queries[i][0], (double)1 / temp});
    }
    return ans;
}