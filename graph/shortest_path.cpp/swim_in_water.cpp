#include <bits/stdc++.h>
using namespace std;
int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist(n, vector<int>(n, 0));
    dist[0][0]=1;
    pq.push({grid[0][0], {0, 0}});
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int m = p.first;
        int x = p.second.first;
        int y = p.second.second;
        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < n && Y < n && X >= 0 && Y >= 0 && !dist[X][Y])
            {
                dist[X][Y]=1;
                int M=max(m,grid[X][Y]);
                if(X==n-1 && Y==n-1)return M;
                pq.push({M, {X, Y}});
            }
        }
    }
    return dist[n - 1][n - 1];
}
int main()
{
    vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<swimInWater(grid);
}