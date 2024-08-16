#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &nums, int l, int r, vector<vector<int>> &dp)
{
    if (r < l)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    int ans = INT_MIN;
    for (int k = l; k <= r; k++)
    {
        int b = nums[l - 1] * nums[r + 1] * nums[k];
        int left = util(nums, l, k - 1, dp);
        int right = util(nums, k + 1, r, dp);
        ans = max(ans, left + right + b);
    }
    return ans;
}
int maxCoins(vector<int> &nums)
{
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    int s = nums.size();
    // vector<vector<int>>dp(s,vector<int>(s,-1));
    // return util(nums,1,s-2,dp);
    vector<vector<int>> dp(s, vector<int>(s, 0));
    for (int l = s - 2; l > 0; l--)
    {
        for (int r = 1; r < s - 1; r++)
        {
            if (r < l)
                continue;
            int ans = INT_MIN;
            for (int k = l; k <= r; k++)
            {
                int b = nums[l - 1] * nums[r + 1] * nums[k];
                int left = dp[l][k - 1];
                int right = dp[k + 1][r];
                ans = max(ans, left + right + b);
            }
            dp[l][r] = ans;
        }
    }
    return dp[1][s - 2];
}

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    cout << maxCoins(nums);
}