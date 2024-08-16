#include <bits/stdc++.h>
using namespace std;
int help(vector<int> &protein, vector<int> &fat, vector<int> &carbohydrate, int ind, int pro, int fats, int P, int F, vector<vector<vector<int>>> &dp)
{
    if (pro >= P && fats >= F)
    {
        return 0;
    }
    if (ind >= protein.size())
    {
        return 1e9;
    }
    if (dp[ind][pro][fats] != -1)
    {
        return dp[ind][pro][fats];
    }
    int take = help(protein, fat, carbohydrate, ind + 1, min(P, pro + protein[ind]), min(F, fats + fat[ind]), P, F, dp) + carbohydrate[ind];
    int dont_take = help(protein, fat, carbohydrate, ind + 1, pro, fats, P, F, dp);
    return dp[ind][pro][fats] = min(take, dont_take);
}
int main()
{
    int P, F;
    cin >> P >> F;
    int n;
    cin >> n;
    vector<int> protein(n), fat(n), carbohydrate(n);
    for (int i = 0; i < n; i++)
    {
        cin >> protein[i] >> fat[i] >> carbohydrate[i];
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(P + 1, vector<int>(F + 1, 1e9)));

    // int ans = help(protein, fat, carbohydrate, 0, 0, 0, P, F, dp);
    dp[n][P][F] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = P; j >= 0; j--)
        {
            for (int k = F; k >= 0; k--)
            {
                int take = dp[i + 1][min(P, j + protein[i])][min(F, k + fat[i])] + carbohydrate[i];
                int dont_take = dp[i + 1][j][k];
                dp[i][j][k] = min(take, dont_take);
            }
        }
    }
    int ans = dp[0][0][0];
    if (ans == 1e9)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}