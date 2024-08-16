#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int f(int ind, int flag, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 1;
    if (dp[ind][flag] != -1)
        return dp[ind][flag];
    int take = 0;
    int not_take = 0;
    if (flag == 2)
    {
        take = f(ind + 1, ind % 2, n, dp);
        not_take = f(ind + 1, flag, n, dp);
    }
    else if (flag == 1 && ind % 2 == 0)
    {
        take = f(ind + 1, 0, n, dp);
        not_take = f(ind + 1, flag, n, dp);
    }
    else if (flag == 0 && ind % 2 != 0)
    {
        take = f(ind + 1, 1, n, dp);
        not_take = f(ind + 1, flag, n, dp);
    }
    else
        not_take = f(ind + 1, flag, n, dp);

    return dp[ind][flag] = (take % mod + not_take % mod) % mod;
}
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << f(0, 2, n, dp) - 1;

    return 0;
}