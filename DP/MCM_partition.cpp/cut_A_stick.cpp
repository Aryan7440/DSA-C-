#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (j <= 1 + i)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        int c = (cuts[j] - cuts[i]);
        int l = f(i, k, cuts, dp);
        int r = f(k, j, cuts, dp);
        ans = min(ans, +l + r + c);
    }
    return dp[i][j] = ans;
}
int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return f(0, cuts.size()-1, cuts, dp);
    for (int i = cuts.size()-1; i >= 0; i--)
    {
        for (int j = 0; j <= cuts.size()-1; j++)
        {
            if (j <= i + 1)
                continue;
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                int c = (cuts[j] - cuts[i]);
                int l = dp[i][k];
                int r = dp[k][j];
                ans = min(ans, l + r + c);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][cuts.size() - 1];
}
int main()
{
    // int n = 7;
    // vector<int> cuts = {1, 3, 4, 5};
    int n = 9;
    vector<int> cuts = {5, 6, 1, 4, 2};
    cout << minCost(n, cuts);
}