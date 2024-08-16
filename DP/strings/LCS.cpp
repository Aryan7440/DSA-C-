#include <bits/stdc++.h>
using namespace std;
int util(string text1, string text2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (text1[i] == text2[j])
        return dp[i][j] = 1 + util(text1, text2, i - 1, j - 1, dp);
    int l = util(text1, text2, i - 1, j, dp);
    int r = util(text1, text2, i, j - 1, dp);
    return dp[i][j] = max(l, r);
}
// int longestCommonSubsequence(string text1, string text2)
// {
//     int n = text1.size();
//     int m = text2.size();
//     // vector<vector<int>> dp(n, vector<int>(m, -1));
//     // return util(text1, text2, n - 1, m - 1, dp);

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (text1[i - 1] == text2[j - 1])
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }
//     return dp[n][m];
// }
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return curr[m];
}
int main()
{
    // string text1 ="intention" ,text2 ="execution";
    string text1 ="horse" ,text2 ="ros";
    // string text1 ="ezupkr" ,text2 ="ubmrapg";
    cout<<longestCommonSubsequence(text1,text2);
}