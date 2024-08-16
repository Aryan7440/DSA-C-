#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int WaysToBuild(int ind, int H, vector<int> &blocks, vector<vector<int>> &dp)
{
    if (ind == blocks.size())
        return H == 0;
    if (dp[ind][H] != -1)
        return dp[ind][H];
    int res = 0;
    for (int i = 0; i <= H / blocks[ind]; i++)
    {
        res = (res % mod + WaysToBuild(ind + 1, H - (blocks[ind] * i), blocks, dp) % mod) % mod;
    }
    return dp[ind][H] = res;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, h;
        cin >> n >> h;
        vector<int> blocks(n);
        for (int i = 0; i < n; i++)
            cin >> blocks[i];
        vector<vector<int>> dp(n, vector<int>(h + 1, -1));
        cout << WaysToBuild(0, h, blocks, dp) << endl;
    }

    return 0;
}