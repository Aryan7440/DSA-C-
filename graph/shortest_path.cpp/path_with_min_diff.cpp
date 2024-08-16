#include <bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> difference(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    difference[0][0] = 0;
    pq.push({difference[0][0], {0, 0}});

    while (!pq.empty())
    {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        int x = curr.second.first;
        int y = curr.second.second;
        int diff = curr.first;

        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (X < n && X >= 0 && Y < m && Y >= 0)
            {
                int n_diff = max(abs(heights[X][Y] - heights[x][y]), diff);
                if (difference[X][Y] > n_diff)
                {
                    difference[X][Y] = n_diff;
                    pq.push({difference[X][Y], {X, Y}});
                }
            }
        }
    }
    return difference[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << minimumEffortPath(heights);
}