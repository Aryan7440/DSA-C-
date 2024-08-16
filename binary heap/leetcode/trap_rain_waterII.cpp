#include <bits/stdc++.h>
using namespace std;

int trapRainWater(vector<vector<int>> &heightMap)
{
    int n = heightMap.size();
    int m = heightMap[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    // pair<int,pair<int,int>> p
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minheap;

    for (int i = 0; i < n; i++)
    {
        minheap.push({heightMap[i][0], {i, 0}});
        vis[i][0] = 1;

        minheap.push({heightMap[i][m - 1], {i, m - 1}});
        vis[i][m - 1] = 1;
    }
    for (int j = 1; j < m - 1; j++)
    {
        minheap.push({heightMap[0][j], {0, j}});
        vis[0][j] = 1;

        minheap.push({heightMap[n - 1][j], {n - 1, j}});
        vis[n - 1][j] = 1;
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int water = 0;

    while (!minheap.empty())
    {
        auto t = minheap.top();
        int h = t.first;
        int x = t.second.first;
        int y = t.second.second;

        minheap.pop();

        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X >= 0 && X < n && Y >= 0 && Y < m && !vis[X][Y])
            {
                if (h <= heightMap[X][Y])
                {
                    vis[X][Y] = 1;
                    minheap.push({heightMap[X][Y], {X, Y}});
                }
                else
                {
                    water += h - heightMap[X][Y];
                    vis[X][Y] = 1;
                    minheap.push({h, {X, Y}});
                }
            }
        }
    }
    return water;
}
int main()
{
    vector<vector<int>> heightMap = { {1, 4, 3, 1, 3, 2},
                                      {3, 2, 1, 3, 2, 4},
                                      {2, 3, 3, 2, 3, 1} };
    cout<<trapRainWater(heightMap);

}