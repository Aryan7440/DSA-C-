#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
int main()
{

    int c, m, n;
    cin >> c >> m >> n;

    vector<int> zero(c, 0), one(c, 0);
    for (int ind = 0; ind < c; ind++)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zero[ind]++;
            else
                one[ind]++;
        }
    }
    vector<vector<vector<long long>>> dp(c + 1, vector<vector<long long>>(m + 1, vector<long long>(n, 0)));
    for (int i = c - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int take = 0;
                if (j >= zero[i] && k >= one[i])
                    take = 1 + dp[i + 1][j - zero[i]][k - one[i]];
                int not_take = dp[i + 1][j][k];
                dp[i][j][k] = max(take, not_take);
            }
        }
    }
    cout << dp[0][m][n];
    return 0;
}