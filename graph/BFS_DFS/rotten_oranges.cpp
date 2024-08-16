#include <bits/stdc++.h>
using namespace std;

int rotten(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    vector<int> di = {-1, 0, 1, 0};
    vector<int> dj = {0, 1, 0, -1};
    int org = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                // visited[i][j] = 1;
            }
            else if (grid[i][j] == 1)
                org++;
        }
    }
    // if(q.size()==0)return -1;
    if (org == 0)
        return 0;
    int time = -1;
    int corg = 0;
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int I = p.first + di[j];
                int J = p.second + dj[j];
                if (I < n && I >= 0 && J < m && J >= 0 && grid[I][J] == 1)// && visited[I][J] == 0
                {
                    // visited[I][J] = 1;
                    grid[I][J]=2;
                    corg++;
                    q.push({I, J});
                }
            }
        }
        time++;
    }
    if (org == corg)
        return time;
    return -1;
}

int main()
{
    // vector<vector<int>> grid = {{0, 1, 2},
    //                             {0, 1, 2},
    //                             {2, 1, 1}};
    // vector<vector<int>> grid = {{1}, {2}};
    // vector<vector<int>> grid = {{0, 2}};
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    // vector<vector<int>> grid={{2,1,1},{0,1,1},{1,0,1}};
    cout<< rotten(grid);
}