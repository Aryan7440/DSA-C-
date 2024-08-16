#include <bits/stdc++.h>
using namespace std;
bool util(vector<int> &jumps, int ind, int s, vector<vector<int>> &dp)
{
    if (s == 0)
        return true;
    if (ind == jumps.size())
        return false;
    if (dp[ind][s] != -1)
        return dp[ind][s];
    bool jump = 0;
    if (s - jumps[ind] >= 0)
        jump = util(jumps, ind + 1, s - jumps[ind], dp);
    bool no_jump = util(jumps, ind + 1, s, dp);
    return dp[ind][s] = jump || no_jump;
}
void jumpPossibility(vector<int> &jumps, int s)
{
    int n = jumps.size();
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
    if (util(jumps, 0, s, dp))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
// void jumpPossibility(vector<int> &jumps, int s)
// {
//     int n = jumps.size();
//     vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
//     dp[n][0] = 1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j <= s; j++)
//         {
//             dp[i][j] = dp[i + 1][j - jumps[i]] || dp[i + 1][j];
//         }
//     }
//     if (dp[0][s])
//         cout << "YES" << endl;
//     else
//         cout << "NO" << endl;
// }
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
        jumpPossibility(jumps, s);
    }
    return 0;
}
// int main()
// {
//     // vector<int> jumps = {1, 2, 10, 3, 20};
//     // jumpPossibility(jumps, 20);
//     vector<int> jumps = {1, 8};
//     jumpPossibility(jumps, 10);
// }