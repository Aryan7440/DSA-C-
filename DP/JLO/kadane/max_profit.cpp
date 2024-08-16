#include <bits/stdc++.h>
using namespace std;
long long util(vector<vector<long long>> &inter, int ind, vector<long long> &dp)
{
    if (ind >= inter.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int n = inter.size();
    int l = ind, r = n;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if (inter[ind][1] <= inter[mid][0])
            r = mid;
        else
            l = mid;
    }
    long long take = inter[ind][2] + util(inter, r, dp);
    long long not_take = util(inter, ind + 1, dp);
    return dp[ind] = max(take, not_take);
}
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
    vector<long long> dp(n, -1);
    cout << util(inter, 0, dp) << endl;
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