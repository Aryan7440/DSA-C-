#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int util(vector<string> &words, string target, int i, int k, vector<vector<int>> &dp)
{
    if (k == target.size())
    {
        return 1;
    }
    if (i >= words[0].size())
        return 0;
    if (dp[i][k] != -1)
        return dp[i][k];
    int ans = 0;
    for (int j = 0; j < words.size(); j++)
    {
        for (int c = i; c < words[j].size(); c++)
        {
            if (words[j][c] == target[k])
            {
                ans = (ans % mod + util(words, target, c + 1, k + 1, dp) % mod) % mod;
            }
        }
    }
    return dp[i][k] = ans;
}
// int numWays(vector<string> &words, string target)
// {
//     int n = words[0].size();
//     int m = target.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     // return util(words,target,0,0,dp);

//     for (int i = 0; i <= n; i++)
//         dp[i][m] = 1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = m - 1; j >= 0; j--)
//         {
//             int ans = 0;
//             for (int k = 0; k < words.size(); k++)
//             {
//                 if (words[k][i] == target[j])
//                 {
//                     ans = (ans % mod + dp[i + 1][j + 1] % mod) % mod;
//                 }
//             }
//             ans = (ans % mod + dp[i + 1][j] % mod) % mod;
//             dp[i][j] = ans;
//         }
//     }
//     return dp[0][0];
// }
int numWays(vector<string> &words, string target)
{
    int n = words[0].size();
    int m = target.size();
    int mod = 1e9+7;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    vector<vector<int>> count(n, vector<int>(26, 0));
    for (const string &word : words)
    {
        for (int i = 0; i < n; i++)
        {
            count[i][word[i] - 'a']++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            dp[j + 1] = dp[j+1]%mod  + (dp[j]%mod * count[i][target[j] - 'a'] % mod)%mod;
            dp[j + 1] %= mod;
        }
    }

    return dp[m];
}

int main()
{
    vector<string> words = {"abba", "baab"};
    string target = "bab";
    cout << numWays(words, target);
}