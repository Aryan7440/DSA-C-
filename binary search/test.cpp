#include <bits/stdc++.h>
using namespace std;
// long long func(vector<vector<long long>> &inter, int ind, vector<long long> &dp)
// {
//     if (ind >= inter.size())
//         return 0;
//     if (dp[ind] != -1)
//         return dp[ind];
//     int n = inter.size();
//     int l = ind, r = n;
//     while (l + 1 < r)
//     {
//         int mid = l + (r - l) / 2;
//         if (inter[ind][1] <= inter[mid][0])
//             r = mid;
//         else
//             l = mid;
//     }
//     long long take = inter[ind][2] + func(inter, r, dp);
//     long long not_take = func(inter, ind + 1, dp);
//     return dp[ind] = max(take, not_take);
// }
void solve()
{
    int n;
    cin >> n;
    vector<vector<long long>> inter;
    for (int i = 0; i < n; i++)
    {
        long long l, r, x;
        cin >> l >> r >> x;
        inter.push_back({l, r, r - l + x});
    }
    sort(inter.begin(), inter.end());
    // vector<long long> dp(n, -1);
    vector<long long> dp(n + 1, 0);
    // dp[n-1]=inter[n-1][2];
    for (int ind = n - 1; ind >= 0; ind--)
    {
        long long l = ind, r = n;
        while (l + 1 < r)
        {
            long long mid = l + (r - l) / 2;
            if (inter[ind][1] <= inter[mid][0])
                r = mid;
            else
                l = mid;
        }
        long long take = inter[ind][2] + dp[r];
        long long not_take = dp[ind + 1];
        dp[ind] = max(take, not_take);
    }

    // cout << func(inter, 0, dp) << endl;
    cout << dp[0] << endl;
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