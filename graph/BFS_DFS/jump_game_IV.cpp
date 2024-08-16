#include <bits/stdc++.h>
using namespace std;
int minJumps(vector<int> &arr)
{
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]].push_back(i);
    }
    vector<int> vis(arr.size(), 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    int ans = 0;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int ind = q.front();
            if (ind == arr.size() - 1)
                return ans;
            q.pop();
            if (ind + 1 < arr.size() && !vis[ind + 1])
            {
                q.push(ind + 1);
                vis[ind + 1] = 1;
            }
            if (ind - 1 >= 0 && !vis[ind - 1])
            {
                q.push(ind - 1);
                vis[ind - 1] = 1;
            }
            for (auto j : mp[arr[ind]])
            {
                if (!vis[j])
                {
                    q.push(j);
                    vis[j] = 1;
                }
            }
            mp[arr[ind]]={};
        }
        ans++;
    }
    return -1;
}
int main()
{
    vector<int>arr={100,-23,-23,404,100,23,23,23,3,404};
    cout<<minJumps(arr);
}