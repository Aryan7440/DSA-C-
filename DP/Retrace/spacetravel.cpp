#include <bits/stdc++.h>
using namespace std;
long long util(vector<long long> &gravity, vector<long long> &mass, vector<long long> &value, int ind, int m, int f)
{
    if (ind == gravity.size())
        return 0;
    if (m * gravity[ind] > f)
        return -1e9;
    long long take = 0;
    if ((m + mass[ind]) * gravity[ind] <= f)
        take = value[ind] + util(gravity, mass, value, ind + 1, m + mass[ind], f);
    long long not_take = util(gravity, mass, value, ind + 1, m, f);
    return max(take, not_take);
}
int main()
{
    int n, f;
    cin >> n >> f;
    vector<long long> mass(n), value(n), gravity(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gravity[i];
        cin >> mass[i];
        cin >> value[i];
    }
    long long M = 0;
    for (int i = 0; i < n; i++)
    {
        M = max(M, f / gravity[i]);
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(M + 1, 0));
    vector<vector<bool>> taken(n + 1, vector<bool>(M + 1, false));
    // cout<<util(gravity,mass,value,0,0,f);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = M; j >= 0; j--)
        {
            if (j > f / gravity[i])
                dp[i][j] = -1e9;
            else
            {
                long long take = 0;
                if ((j + mass[i]) * gravity[i] <= f)
                    take = value[i] + dp[i + 1][j + mass[i]];
                long long not_take = dp[i + 1][j];
                if (take > not_take)
                    taken[i][j] = true;
                dp[i][j] = max(take, not_take);
            }
        }
    }
    // cout<<dp[0][0];
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n)
    {
        if (taken[i][j])
        {
            ans.push_back(i + 1);
            j += mass[i];
        }
        i++;
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";

    return 0;
}