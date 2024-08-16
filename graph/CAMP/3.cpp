#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    int n, m;
    cin >> n, m;
    vector<vector<int>> grid(n);
    // vector<vector<int>>vis(n,0);
    queue<pair<int, int>> q1, q2;
    vector<vector<int>> dist1(n, vector<int>(m, -1));
    vector<vector<int>> dist2(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            grid[i].push_back(temp);
            if (temp == 1)
            {
                q1.push({i, j});
                dist1[i][j] = 0;
            }
            else if (temp == 2)
            {
                q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }

    while (!q1.empty())
    {
        int s = q1.size();
        for (int i = 0; i < s; i++)
        {
            auto x = q1.front().first;
            auto y = q1.front().second;
            // vis[x][y]=
            q1.pop();
            for (int j = 0; j < 4; j++)
            {
                int X = x + dx[j];
                int Y = y + dy[j];
                if (X >= 0 && Y >= 0 && X < grid.size() && Y < grid[x].size() && grid[X][Y] == 1 && dist1[X][Y] == -1)
                {
                    dist1[X][Y] = 1 + dist1[x][y];
                    q1.push({X, Y});
                }
            }
        }
    }
    while (!q2.empty())
    {
        int s = q2.size();
        for (int i = 0; i < s; i++)
        {
            auto x = q2.front().first;
            auto y = q2.front().second;
            // vis[x][y]=
            q2.pop();
            for (int j = 0; j < 4; j++)
            {
                int X = x + dx[j];
                int Y = y + dy[j];
                if (X >= 0 && Y >= 0 && X < grid.size() && Y < grid[x].size() && grid[X][Y] == 2 && dist2[X][Y] == -1)
                {
                    dist2[X][Y] = 1 + dist2[x][y];
                    q2.push({X, Y});
                }
            }
        }
    }
    // vector<vector<in
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!grid[i][j])
            {
                if (dist1[i][j] == dist2[i][j])
                    grid[i][j] = 3;
                else if (dist1[i][j] > dist2[i][j])
                {
                    grid[i][j] = 2;
                }
                else
                    grid[i][j] = 1;
            }
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    // for(int i=0;i<n;i++)
    // {
    //     for
    // }
}