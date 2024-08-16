#include <bits/stdc++.h>
using namespace std;
int util(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &dp)
{
    if (r == triangle.size())
        return 0;
    if (dp[r][c] != -1)
        return dp[r][c];
    int i = 0;
    int j = 0;
    if (c >= 0)
        i = util(triangle, r + 1, c, dp) + triangle[r][c];
    if (c < triangle[r].size())
        j = util(triangle, r + 1, c + 1, dp) + triangle[r][c];
    return dp[r][c] = min(i, j);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return util(triangle, 0, 0, dp);
}
int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(triangle);
}