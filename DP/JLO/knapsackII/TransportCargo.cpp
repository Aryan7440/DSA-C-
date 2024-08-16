#include <bits/stdc++.h>
using namespace std;
bool util(vector<long long> &V, vector<long long> &W, vector<long long> &vi, int maxV, vector<vector<long long>> &dp, int ind, int vl, int wl)
{
    int vr = (ind == 0) ? 0 : vi[ind - 1] - vl;
    if (ind == V.size())
    {
        return (wl == 0);
    }
    if (dp[ind][wl] != -1)
    {
        return dp[ind][wl];
    }
    bool take = false, dont_take = false;
    if (vl + V[ind] <= maxV)
    {
        take = util(V, W, vi, maxV, dp, ind + 1, vl + V[ind], wl - W[ind]);
    }
    if (vr + V[ind] <= maxV)
    {
        dont_take = util(V, W, vi, maxV, dp, ind + 1, vl, wl);
    }
    return dp[ind][wl] = take || dont_take;
}
int main()
{

    int n, v;
    cin >> n >> v;
    vector<long long> V(n), W(n);
    vector<long long> vi(n + 1);
    long long sumV = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> W[i] >> V[i];
        sumV += V[i];
        vi[i] = sumV;
    }
    long long sumW = accumulate(W.begin(), W.end(), 0);

    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(v + 1, vector<bool>(sumW + 1, false)));
    for (int i = 0; i <= v; i++)
        dp[n][i][0] = true;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int vl = v - V[i]; vl >= 0; vl--)
        {
            for (int k = W[i]; k <= sumW; k++)
            {
                bool takeLeft = false, takeRight = false;
                if (vl + V[i] <= v)
                {
                    takeLeft = dp[i + 1][vl + V[i]][k - W[i]];
                }
                takeRight = dp[i + 1][vl][k];
                dp[i][vl][k] = takeLeft || takeRight;
            }
        }
    }
    long long ans = LONG_LONG_MAX;
    for (int i = 0; i <= v; i++)
    {
        for (int j = 0; j <= sumW; j++)
        {
            if (dp[0][i][j] && sumV - j <= v)
            {
                ans = min(ans, abs(j - (sumW - j)));
            }
        }
    }
    cout << ans;
    return 0;
}