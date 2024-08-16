#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
void mark(vector<vector<int>> &grid, int x, int y, int m, int &count)
{
    count++;
    grid[x][y] = m;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (grid[X][Y] == 1)
        {
            mark(grid, X, Y, m, count);
        }
    }
}
int check(vector<vector<int>> &grid, int x, int y, unordered_map<int, int> &sizes)
{
    unordered_set<int> set;
    int count = 1;
    grid[x][y] = -1;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (grid[X][Y] > 1 && set.find(grid[X][Y]) == set.end())
        {
            count += sizes[grid[X][Y]];
            set.insert(grid[X][Y]);
        }
    }
    return count;
}
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = 1;
    unordered_map<int, int> sizes;
    int max_size = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                m++;
                int count = 0;
                mark(grid, i, j, m, count);
                sizes[m] = count;
                max_size = max(max_size, count);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                ans = max(ans, check(grid, i, j, sizes));
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid={{1,0},{0,1}};
    cout<<largestIsland(grid);
}