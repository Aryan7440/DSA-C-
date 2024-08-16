#include <bits/stdc++.h>
using namespace std;
int Maxhappiness(vector<int> &hap, int ind, int chocolate, vector<vector<int>> &dp)
{
    if (chocolate == 0 || ind == hap.size())
        return 0;
    if (dp[ind][chocolate] != -1)
        return dp[ind][chocolate];
    int takeS = 0;
    if (chocolate - ind - 1 >= 0)
        takeS = Maxhappiness(hap, ind, chocolate - ind - 1, dp) + hap[ind];
    int not_take = Maxhappiness(hap, ind + 1, chocolate, dp);
    return dp[ind][chocolate] = max(takeS, not_take);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> hap(n);
        for (int i = 0; i < n; i++)
        {
            cin >> hap[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // cout << Maxhappiness(hap, 0, n, dp) << endl;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= n; j++)
            {
                int take = 0;
                if (j - i - 1 >= 0)
                {
                    take = dp[i][j - i - 1] + hap[i];
                }
                dp[i][j] = max(take, dp[i + 1][j]);
            }
        }
        // cout << dp[0][n] << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << "   ";
            }
            cout << endl;
        }
    }
}