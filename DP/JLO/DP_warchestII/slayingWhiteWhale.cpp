#include <bits/stdc++.h>
using namespace std;
int util(int D, int ind, vector<long long> &damage, vector<long long> &displeasure, vector<vector<long long>> &dp)
{
    if (D <= 0)
        return 0;
    if (ind == damage.size())
        return 1e9;
    if (dp[ind][D] != -1)
        return dp[ind][D];
    long long take = util(D - damage[ind], ind, damage, displeasure, dp) + displeasure[ind];
    long long not_take = util(D, ind + 1, damage, displeasure, dp);
    return dp[ind][D] = min(take, not_take);
}
long long DPS(int D, vector<long long> &damage, vector<long long> &displeasure)
{
    int n = damage.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(D + 1, 0));
    for (int i = 0; i <= D; i++)
    {
        dp[n][i] = 1e9;
    }
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= D; j++)
        {
            if (j < damage[i])
                dp[i][j] = min(dp[i + 1][j], displeasure[i]);
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j - damage[i]] + displeasure[i]);
        }
    }
    return dp[0][D];
}
long long OPDPSS(int D, vector<long long> &damage, vector<long long> &displeasure)
{
    int n = damage.size();
    vector<long long> dpp(D + 1, 1e9), dpc(D + 1, 1e9);
    dpp[0] = 0;
    dpc[0] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= D; j++)
        {
            if (j < damage[i])
                dpc[j] = min(dpp[j], displeasure[i]);
            else
                dpc[j] = min(dpp[j], dpc[j - damage[i]] + displeasure[i]);
        }
        dpp = dpc;
    }
    return dpc[D];
}
int main()
{

    long long n, D;
    cin >> n >> D;

    vector<long long> damage(n), limit(n), displeasure(n);

    for (int i = 0; i < n; i++)
    {
        cin >> damage[i];
        cin >> limit[i];
        cin >> displeasure[i];
    }
    for (int i = 0; i < n; i++)
    {
        D -= limit[i] * damage[i];
    }
    if (D <= 0)
    {
        cout << 0 << endl;
        return 0;
    }
    // cout << DPS(D, damage, displeasure) << endl;
    cout << OPDPSS(D, damage, displeasure) << endl;

    // cout << util(D, 0, damage, displeasure, dp);

    return 0;
}