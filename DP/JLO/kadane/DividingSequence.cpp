#include <bits/stdc++.h>
using namespace std;
long long util(vector<long long> &nums, int prv, int cur, vector<vector<long long>> &dp)
{
    if (cur == nums.size())
        return 0;
    if (dp[prv + 1][cur] != -1)
        return dp[prv + 1][cur];
    long long take = 0;
    long long not_take = 0;
    if (prv == -1 || nums[cur] % nums[prv] == 0)
        take = 1 + util(nums, cur, cur + 1, dp);
    not_take = util(nums, prv, cur + 1, dp);
    return dp[prv + 1][cur] = max(take, not_take);
}
int main()
{

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    // sort(nums.begin(), nums.end());
    // vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int j = i; j >= -1; j--)
    //     {
    //         int take = 0;
    //         if (j == -1 || (nums[i] % nums[j]) == 0)
    //         {
    //             take = dp[i + 1][i + 1] + 1;
    //         }
    //         int not_take = dp[i + 1][j + 1];
    //         dp[i][j + 1] = max(take, not_take);
    //     }
    // }
    // // vector<vector<long long>> dp(n + 1, vector<long long>(n, -1));
    // // cout << util(nums, -1, 0, dp) << endl;
    // cout << dp[0][0];
    vector<int> dp(n, 1);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((nums[i] % nums[j]) == 0)
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}