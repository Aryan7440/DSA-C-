#include <bits/stdc++.h>
using namespace std;

int check(int x1, int y1, int x2, int y2, int r1)
{
    double X = (x2 - x1);
    double Y = (y2 - y1);
    double dist = X * X + Y * Y;
    return (double)sqrt(dist) <= r1;
}
int dfs(vector<vector<int>> &bombs, int ind, vector<int> &vis, vector<vector<int>> &graph)
{
    vis[ind] = 1;
    int res = 0;
    int n = bombs.size();
    int x = bombs[ind][0];
    int y = bombs[ind][1];
    int r = bombs[ind][2];
    for (int i = 0; i < graph[ind].size(); i++)
    {
        if (!vis[graph[ind][i]])
        {
            res += 1 + dfs(bombs, graph[ind][i], vis, graph);
        }
    }
    return res;
}
int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                int x = bombs[i][0];
                int y = bombs[i][1];
                int r = bombs[i][2];

                int xi = bombs[j][0];
                int yi = bombs[j][1];
                if (check(x, y, xi, yi, r))
                    graph[i].push_back(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> vis(n, 0);
        ans = max(ans, 1 + dfs(bombs, i, vis, graph));
    }
    return ans;
}
int main()
{
    vector<vector<int>> bombs={{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
    cout<<maximumDetonation(bombs);
}