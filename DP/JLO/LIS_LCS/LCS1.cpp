#include <bits/stdc++.h>
using namespace std;
int longestIncereasingSubsequence(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n] == s2[m])
    {
        return dp[n][m] = 1 + longestIncereasingSubsequence(s1, s2, n - 1, m - 1, dp);
    }
    return dp[n][m] = max(longestIncereasingSubsequence(s1, s2, n - 1, m, dp), longestIncereasingSubsequence(s1, s2, n, m - 1, dp));
}
int LCS(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string s1 = "broalgouniversity";
    string s2 = "bestmentors";
    cout << LCS(s1, s2);
}