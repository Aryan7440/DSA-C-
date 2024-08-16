#include <bits/stdc++.h>
using namespace std;

void convert(vector<pair<int, int>> &p)
{
    int x = p[0].first;
    int y = p[0].second;
    p[0].first = 0;
    p[0].second = 0;
    for (int i = 1; i < p.size(); i++)
    {
        p[i].first = p[i].first - x;
        p[i].second = p[i].second - y;
    }
}
void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<int> &di, vector<int> &dj, vector<pair<int, int>> &ans)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[x][y] = 1;
    ans.push_back({x, y});
    for (int i = 0; i < 4; i++)
    {
        int I = x + di[i];
        int J = y + dj[i];
        if (I >= 0 && I < n && J >= 0 && J < m && grid[I][J] == 1 && !vis[I][J])
        {
            dfs(I, J, grid, vis, di, dj, ans);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                vector<pair<int, int>> temp;
                dfs(i, j, grid, vis, di, dj, temp);
                convert(temp);
                s.insert(temp);
            }
        }
    }
    return s.size();
}

int main()
{
    // vector<vector<int>> grid = { {1, 1, 0, 0, 0},
    //                              {1, 1, 0, 0, 0},
    //                              {0, 0, 0, 1, 1},
    //                              {0, 0, 0, 1, 1} };
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};
    cout<< countDistinctIslands(grid);
}