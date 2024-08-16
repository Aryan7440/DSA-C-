#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    vector<vector<int>> dpn(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        dpn[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            dpn[i][i + 1] = 3;
        }
        else
            dpn[i][i + 1] = 2;
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
            dpn[i][j] = dpn[i + 1][j] + dpn[i][j - 1] - dpn[i + 1][j - 1];
            if (dp[i][j])
            {
                dpn[i][j]++;
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << dpn[l - 1][r - 1] << endl;
    }
}
int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}