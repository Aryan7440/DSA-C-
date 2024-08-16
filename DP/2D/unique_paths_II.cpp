#include <bits/stdc++.h>
using namespace std;
// int util(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &dp)
// {
//     int n = obstacleGrid.size();
//     int m = obstacleGrid[0].size();
//     if (i >= n || j >= m)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (obstacleGrid[i][j] == 1)
//         return 0;
//     if (i == n - 1 && j == m - 1)
//         return dp[n - 1][m - 1] = 1;

//     int r = util(obstacleGrid, i, j + 1, dp);
//     int d = util(obstacleGrid, i + 1, j, dp);
//     return dp[i][j] = r + d;
// }
// int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
// {
//     int n = obstacleGrid.size();
//     int m = obstacleGrid[0].size();
//     if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
//         return 0;
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//     dp[1][1] = 1;
//     // return util(obstacleGrid,0,0,dp);
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             if (i == 0 || j == 0)
//             {
//                 dp[i][j] = 0;
//                 continue;
//             }
//             if (obstacleGrid[i - 1][j - 1] == 1)
//                 dp[i][j] = 0;
//             else
//             {
//                 if (i == 1 && j == 1)
//                     continue;
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//     }
//     return dp[n][m];
// }
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
        return 0;
    vector<int> dp(m + 1, 0);
    dp[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (obstacleGrid[i - 1][j - 1] == 1)
                dp[j] = 0;
            else
            {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
    }
    return dp[m];
}
int main()
{
    vector<vector<int>> obstacleGrid = {{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid);
}