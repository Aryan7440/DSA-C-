#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    int oc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                oc++;
            if ((i == 0 || j == 0 || i==n-1 || j==m-1) && grid[i][j] == 1)
            {
                grid[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    int coc = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        coc++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int I = p.first + di[i];
            int J = p.second + dj[i];
            if (I >= 0 && I < n && J >= 0 && J < m && grid[I][J] == 1)
            {
                grid[I][J] = 0;
                q.push({I, J});
            }
        }
    }
    return oc - coc;
}

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                                {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                                {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                                {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
                                {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                                {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                                {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                                {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                                {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}};
    // vector<vector<int>> grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
    // vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << numEnclaves(grid);
}