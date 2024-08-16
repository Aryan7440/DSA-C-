#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &heights, vector<vector<int>> &vis, int x, int y, vector<vector<int>> &ans)
{
    int n = heights.size();
    int m = heights[0].size();
    vis[x][y]=1;
    if (vis[x][y] == 2)
        ans.push_back({x, y});
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 && Y >= 0 && X < n && Y < m && vis[X][Y] == 0)
        {
            if (heights[X][Y] >= heights[x][y])
                dfs(heights, vis, X, Y, ans);
        }
    }
}
void dfs_(vector<vector<int>> &heights, vector<vector<int>> &vis, int x, int y, vector<vector<int>> &ans)
{
    int n = heights.size();
    int m = heights[0].size();
    if (vis[x][y] == 1)
        ans.push_back({x, y});
    vis[x][y]=2;
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X >= 0 && Y >= 0 && X < n && Y < m && vis[X][Y] <=1)
        {
            if (heights[X][Y] >= heights[x][y])
                dfs_(heights, vis, X, Y, ans);
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++)
    {
        if (vis[0][i] == 0)
            dfs(heights, vis, 0, i, ans);
    }
    for (int i = 1; i < n; i++)
    {
        if (vis[i][0] == 0)
            dfs(heights, vis, i, 0, ans);
    }
    for (int i = 1; i < m; i++)
    {
        if (vis[n - 1][i] <= 1)
            dfs_(heights, vis, n - 1, i, ans);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (vis[i][m - 1] <=1)
            dfs_(heights, vis, i, m - 1, ans);
    }
    return ans;
}
int main()
{
    vector<vector<int>>heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> ans=pacificAtlantic(heights);
    for(auto i: ans)
    {
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
}