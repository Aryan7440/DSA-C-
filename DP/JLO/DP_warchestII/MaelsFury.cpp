#include <bits/stdc++.h>
using namespace std;
// long long util(vector<long long> &W, vector<long long> &C, vector<long long> &U, int ind, int c, int w, vector<vector<vector<long long>>> &dp)
// {
//     if (ind == W.size())
//         return 0;
//     if (dp[ind][c][w] != -1)
//         return dp[ind][c][w];
//     long long take = 0;
//     if (c >= C[ind] && w >= W[ind])
//         take = U[ind] + util(W, C, U, ind + 1, c - C[ind], w - W[ind], dp);
//     long long not_take = util(W, C, U, ind + 1, c, w, dp);
//     return dp[ind][c][w] = max(take, not_take);
// }
long long util(vector<long long> &W, vector<long long> &C, vector<long long> &U, int ind, int c, int w, vector<vector<vector<long long>>> &dp)
{
    if (ind < 0)
        return 0;
    if (dp[ind][c][w] != -1)
        return dp[ind][c][w];
    long long take = 0;
    if (c >= C[ind] && w >= W[ind])
        take = U[ind] + util(W, C, U, ind - 1, c - C[ind], w - W[ind], dp);
    long long not_take = util(W, C, U, ind - 1, c, w, dp);
    return dp[ind][c][w] = max(take, not_take);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m, c;
    cin >> n >> m >> c;
    vector<long long> W(n), C(n), U(n);
    vector<pair<long long, long long>> M(m);
    for (int i = 0; i < n; i++)
    {
        cin >> W[i];
        cin >> C[i];
        cin >> U[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> M[i].first;
        cin >> M[i].second;
    }

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(c + 1, vector<long long>(1001, 0)));
    // vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(c + 1, vector<long long>(1001, -1)));
    // vector<vector<long long>> dp(1005, vector<long long>(1005, 0));
    // int N = 1005;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = N - 1; j >= W[i - 1]; j--)
    //     {
    //         for (int k = N - 1; k >= C[i - 1]; k--)
    //         {
    //             dp[j][k] = max(dp[j][k], dp[j - W[i - 1]][k - C[i - 1]] + U[i - 1]);
    //         }
    //     }
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = C[i - 1]; j <= c; j++)
    //     {
    //         for (int k = W[i - 1]; k <= 1000; k++)
    //         {
    //             dp[j][k] = max(dp[j][k], dp[j - C[i - 1]][k - W[i - 1]] + U[i - 1]);
    //         }
    //     }
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = C[i - 1]; j <= c; j++)
    //     {
    //         for (int k = W[i - 1]; k <= 1000; k++)
    //         {
    //             dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - C[i - 1]][k - W[i - 1]] + U[i - 1]);
    //         }
    //     }
    // }
    // vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(1000 + 1, vector<long long>(1001, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = C[i]; j <= c; j++)
        {
            for (int k = W[i]; k <= 1000; k++)
            {
                long long take = U[i] + dp[i + 1][j - C[i]][k - W[i]];
                long long not_take = dp[i + 1][j][k];
                dp[i][j][k] = max(take, not_take);
            }
        }
    }

    // vector<vector<long long>> dp(1001, vector<long long>(1001, 0));

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = C[i]; j <= 1000; j++)
    //     {
    //         for (int k = W[i]; k <= 1000; k++)
    //         {
    //             long long take = U[i] + dp[j - C[i]][k - W[i]];
    //             long long not_take = dp[j][k];
    //             dp[j][k] = max(take, not_take);
    //         }
    //     }
    // }

    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (M[i].second <= c)
        {
            // ans = max(ans, util(W, C, U, 0, c - M[i].second, M[i].first, dp));
            ans = max(ans, dp[0][c - M[i].second][M[i].first]);
            // ans = max(ans, dp[c - M[i].second][M[i].first]);
            // ans = max(ans, dp[c - M[i].second][M[i].first]);
            // ans = max(ans, dp[n][c - M[i].second][M[i].first]);
            // ans = max(ans, util(W, C, U, n - 1, c - M[i].second, M[i].first, dp));
        }
    }
    cout << ans << endl;

    return 0;
}