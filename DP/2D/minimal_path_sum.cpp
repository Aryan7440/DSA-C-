#include <bits/stdc++.h>
using namespace std;
int util(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();
    if(i==n-1 && j==m-1)return grid[n-1][m-1];
     if (i >= n || j >= m)
        return 1e9; //dont take INT_MAX as it will overflow the integer and number will become negative and min() will change
    if (dp[i][j] != -1)
        return dp[i][j];
   
    int r = util(grid, i, j + 1, dp) + grid[i][j];
    int d = util(grid, i + 1, j, dp) + grid[i][j];
    return dp[i][j] = min(r, d);
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m,1e9);
    dp[0]=grid[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)continue;
            int l=(j==0)?1e9:dp[j-1];
            int d=dp[j];
            dp[j]=min(l,d)+grid[i][j];
        }
    }
    return dp[m-1];    
}
// int minPathSum(vector<vector<int>> &grid)
// {
//     int n = grid.size();
//     int m = grid[0].size();
//     // vector<vector<int>> dp(n, vector<int>(m, -1));
//     // return util(grid, 0, 0, dp);
//     vector<vector<int>> dp(n, vector<int>(m, 1e9));
//     dp[0][0]=grid[0][0];
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(i==0 && j==0)continue;
//             int r=((j==0)?1e9:dp[i][j-1])+grid[i][j];
//             int d=((i==0)?1e9:dp[i-1][j])+grid[i][j];
//             dp[i][j]=min(r,d);
//         }
//     }
//     return dp[n-1][m-1];
// }
int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

    cout<<minPathSum(grid);
}