#include <bits/stdc++.h>
using namespace std;
int util(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int pick = 0, not_pick = 0;
    if (s[i] == t[j])
    {
        pick = util(s, t, i - 1, j - 1, dp);
    }
    not_pick = util(s, t, i - 1, j, dp);
    return dp[i][j] = pick + not_pick;
}
// int numDistinct(string s, string t)
// {
//     int n = s.size(), m = t.size();
//     vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
//     // return util(s,t,n-1,m-1,dp);
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 1;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             unsigned long long pick = 0, not_pick = 0;
//             if (s[i - 1] == t[j - 1])
//             {
//                 pick = dp[i - 1][j - 1];
//             }
//             not_pick = dp[i - 1][j];
//             dp[i][j] = pick + not_pick;
//         }
//     }
//     return dp[n][m];
// }
// int numDistinct(string s, string t)
// {
//     int n = s.size(), m = t.size();
//     vector<double> prev(m + 1, 0);
//     vector<double> curr(m + 1, 0);
//     prev[0] = 1;
//     curr[0] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             double pick = 0, not_pick = 0;
//             if (s[i - 1] == t[j - 1])
//             {
//                 pick = prev[j - 1];
//             }
//             not_pick = prev[j];
//             curr[j] = pick + not_pick;
//         }
//         prev = curr;
//     }
//     return curr[m];
// }
int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<double> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            double pick = 0, not_pick = 0;
            if (s[i - 1] == t[j - 1])
            {
                pick = dp[j - 1];
            }
            not_pick = dp[j];
            dp[j] = pick + not_pick;
        }
    }
    return dp[m];
}
int main()
{
    string s = "babgbag", t = "bag";
    cout<<numDistinct(s,t);
}