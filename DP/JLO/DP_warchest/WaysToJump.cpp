#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int WaysToJump(int ind, int s, vector<int> &jumps, vector<vector<int>> &dp)
{
    if (ind == jumps.size())
        return s == 0;
    if (dp[ind][s] != -1)
        return dp[ind][s];
    int res = 0;
    for (int i = 0; i <= s / jumps[ind]; i++)
    {
        res = (res % mod + WaysToJump(ind + 1, s - (i * jumps[ind]), jumps, dp) % mod) % mod;
    }
    return dp[ind][s] = res;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        vector<int> jumps(n);
        for (int i = 0; i < n; i++)
        {
            cin >> jumps[i];
        }
        vector<vector<int>> dp(n, vector<int>(s + 1, -1));
        cout << WaysToJump(0, s, jumps, dp) << endl;
    }

    return 0;
}