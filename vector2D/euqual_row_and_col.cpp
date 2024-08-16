#include <bits/stdc++.h>
using namespace std;
int equalPairs(vector<vector<int>> &grid)
{
    unordered_map<int, string> rows;
    unordered_map<int, string> cols;
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rows[i] += to_string(grid[i][j]);
            cols[i] += to_string(grid[j][i]);
        }
    }
    int count = 0;
    for (auto r : rows)
    {
        for (auto c : cols)
        {
            if (r.second == c.second)
                count++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> grid={{11,1},{1,11}};
}