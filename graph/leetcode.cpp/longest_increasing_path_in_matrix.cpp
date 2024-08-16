#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int m, n;
vector<int> di = {-1, 0, 1, 0};
vector<int> dj = {0, 1, 0, -1};
int dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &dp)
{
    if (dp[x][y] != -1)
        return dp[x][y];
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
        int I = x + di[i];
        int J = y + dj[i];
        if (I >= 0 && I < n && J >= 0 && J < m && matrix[I][J] > matrix[x][y])
        {
            temp = max(temp, 1 + dfs(matrix, I, J, dp));
        }
    }
    ans = max(ans, temp);
    return dp[x][y] = temp;
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    n = matrix.size();
    m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // dfs(matrix, 0, 0, dp);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dp[i][j]==-1)
            {
                dfs(matrix, i, j, dp);
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>>matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(matrix);
}