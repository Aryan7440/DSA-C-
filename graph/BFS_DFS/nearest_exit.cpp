#include <bits/stdc++.h>
using namespace std;

int nearestExit(vector<vector<char>> &maze, vector<int> entrance)
{
    int n = maze.size();
    int m = maze[0].size();
    queue<pair<int, int>> q;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int len = 0;
    q.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';
    while (!q.empty())
    {
        int s = q.size();
        len++;
        for (int j = 0; j < s; j++)
        {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int X = x + dx[i];
                int Y = y + dy[i];
                if (X < n && Y < m && X >= 0 && Y >= 0 && maze[X][Y] == '.')
                {
                    if (X == 0 || Y == 0 || X == n - 1 || Y == m - 1)
                        return len;
                    maze[X][Y] = '+';
                    q.push({X, Y});
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<char>> maze = {{'+', '.', '+', '+', '+', '+', '+'},
                                 {'+', '.', '+', '.', '.', '.', '+'},
                                 {'+', '.', '+', '.', '+', '.', '+'},
                                 {'+', '.', '.', '.', '.', '.', '+'},
                                 {'+', '+', '+', '+', '.', '+', '.'}};
    cout << nearestExit(maze, {0, 1});
}
