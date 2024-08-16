#include <bits/stdc++.h>
using namespace std;
int func(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i == s.size())
    {
        return t.size() - j;
    }
    if (j == t.size())
    {
        return s.size() - i;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = INT_MAX;

    if (s[i] == t[j])
        res = min(res, func(i + 1, j + 1, s, t, dp));

    res = min(res, 1 + func(i, j + 1, s, t, dp));     // delete
    res = min(res, 1 + func(i + 1, j + 1, s, t, dp)); // substitute
    res = min(res, 1 + func(i + 1, j, s, t, dp));     // insert

    return dp[i][j] = res;
}
int funcOP(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][m] = n - i;
    }
    for (int j = 0; j < m; j++)
    {
        dp[n][j] = m - j;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
        }
    }
    return dp[0][0];
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s;
        cin >> t;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // int ans = func(0, 0, s, t, dp);
        // cout << ans << endl;
        cout << funcOP(s, t) << endl;
    }

    return 0;
}