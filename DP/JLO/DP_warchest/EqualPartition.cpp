#include <bits/stdc++.h>
using namespace std;
int half = 0;
bool CanPartition(int ind, int S, vector<int> &chocolates, vector<vector<int>> &dp)
{
    if (ind == chocolates.size())
        return S == half;
    if (dp[ind][S] != -1)
        return dp[ind][S];
    bool take = CanPartition(ind + 1, S + chocolates[ind], chocolates, dp);
    bool notTake = CanPartition(ind + 1, S, chocolates, dp);
    return dp[ind][S] = take || notTake;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> chocolates(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> chocolates[i];
            sum += chocolates[i];
        }
        if (sum % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        half = sum / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        if (CanPartition(0, 0, chocolates, dp))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}