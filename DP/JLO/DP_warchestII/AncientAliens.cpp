#include <bits/stdc++.h>
using namespace std;

string LCS(string s1, string s2)
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
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            ans.push_back(s2[j - 1]);
            j--;
        }
        else
        {
            ans.push_back(s1[i - 1]);
            i--;
        }
    }
    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // int n, m;
    // cin >> n >> m;
    // string s, t;
    // cin >> s;
    // cin >> t;
    // string lcs = LCS(s, t);
    // cout << lcs;
    // string s = "abcd", b = "bcde", c = "cdef";
    string s = "harry", b = "porter", c = "seven";
    cout << LCS(s, LCS(c, b)) << endl;

    return 0;
}