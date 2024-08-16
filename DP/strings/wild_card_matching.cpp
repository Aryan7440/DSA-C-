#include <bits/stdc++.h>
using namespace std;
bool util(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
    {
        if (i < 0)
            return 1;
        return 0;
    }
    if (i < 0)
    {
        while (j >= 0)
        {
            if (p[j] == '*')
                j--;
            else
                return 0;
        }
        return 1;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (p[j] == s[i] || p[j] == '?')
        return dp[i][j] = util(s, p, i - 1, j - 1, dp);
    else if (p[j] == '*')
    {
        return dp[i][j] = util(s, p, i - 1, j, dp) || util(s, p, i, j - 1, dp);
    }
    return 0;
}
// bool isMatch(string s, string p)
// {
//     int n = s.size(), m = p.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     // return util(s, p, n - 1, m - 1, dp);
//     dp[0][0] = 1;
//     for (int j = 1; j <= m; j++)
//     {
//         if (p[j - 1] == '*')
//             dp[0][j] = 1;
//         else
//             break;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
//                 dp[i][j] = dp[i - 1][j - 1];
//             else if (p[j - 1] == '*')
//             {
//                 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//             }
//             else
//                 dp[i][j] = 0;
//         }
//     }
//     return dp[n][m];
// }
bool isMatch(string s, string p)
{
    int n = s.size(), m = p.size();
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    prev[0] = 1;
    for (int j = 1; j <= m; j++)
    {
        if (p[j - 1] == '*')
            prev[j]=1;
        else
            break;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                curr[j] = prev[j - 1];
            else if (p[j - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return prev[m];
}
int main()
{
    string s = "", p = "******";
    cout << isMatch(s, p);
}