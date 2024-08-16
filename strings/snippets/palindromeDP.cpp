#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> palindromeDP(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (i < n - 1 && s[i] == s[i + 1])
            dp[i][i + 1] = 1;
    }
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
                dp[i][j] = 1;
        }
    }
    return dp;
}

int longestPalindrome(string s)
{
    vector<vector<int>> dp = palindromeDP(s);
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (dp[i][j])
                ans = max(ans, j - i + 1);
        }
    }
    return ans;
}