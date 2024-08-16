#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> longestPalindromeSubarray(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
        }
    }
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
            }
        }
    }

    return dp;
}
long long countPalindrome(vector<vector<bool>> dp, int l, int r, vector<vector<long long>> &dpn)
{
    if (l > r)
    {
        return 0;
    }
    if (l == r)
    {
        return 1;
    }
    if (dpn[l][r] != -1)
    {
        return dpn[l][r];
    }
    long long ans = 0;
    if (dp[l][r])
    {
        ans = 1;
    }
    ans += countPalindrome(dp, l + 1, r, dpn) + countPalindrome(dp, l, r - 1, dpn) - countPalindrome(dp, l + 1, r - 1, dpn);
    return dpn[l][r] = ans;
}
void solve()
{
    string s;
    cin >> s;
    vector<vector<bool>> dp = longestPalindromeSubarray(s);
    int q;
    cin >> q;
    vector<vector<long long>> dpn(s.size(), vector<long long>(s.size(), -1));
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << countPalindrome(dp, l - 1, r - 1, dpn) << endl;
    }
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}