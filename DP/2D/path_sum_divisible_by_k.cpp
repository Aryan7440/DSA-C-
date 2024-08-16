#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int util(vector<vector<int>> &grid, int k, int i, int j, int sum)
{
    int n = grid.size();
    int m = grid[0].size();

    if (i == n && m == j)
    {
        if (sum % k == 0)
            return 1;
        else
            return 0;
    }
    if (i >= n || j >= m)
        return 0;
    int left = util(grid, k, i, j + 1, sum + grid[i][j]);
    int right = util(grid, k, i + 1, j, sum + grid[i][j]);
    return (left % mod + right % mod) % mod;
}
int numberOfPaths(vector<vector<int>> &grid, int k)
{
    return util(grid, k, 0, 0, 0);
}
int main()
{
    vector<vector<int>>grid={{5,2,4},{3,0,5},{0,7,2}};
    cout<<numberOfPaths(grid,3);
}