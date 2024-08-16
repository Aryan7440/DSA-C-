#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

    pq.push({0, {0, 0}});
    distance[0][0] = 0;

    while (!pq.empty())
    {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int x = curr.second.first;
        int y = curr.second.second;
        int dist = curr.first;

        for (int i = 0; i < 8; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < n && X >= 0 && Y < n && Y >= 0 && grid[X][Y] == 0 && distance[X][Y] > dist + 1)
            {
                // if(X==n-1 && Y==n-1)return
                distance[X][Y] = dist + 1;
                pq.push({distance[X][Y], {X, Y}});
            }
        }
    }
    return distance[n - 1][n - 1] == INT_MAX ? -1 : distance[n - 1][n - 1];
}