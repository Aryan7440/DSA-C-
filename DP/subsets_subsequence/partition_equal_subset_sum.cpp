#include <bits/stdc++.h>
using namespace std;
// int util(vector<int> &nums, int ind, int k, int sum, vector<vector<int>> &dp) // top down
// {
//     if (k == sum)
//         return true;
//     if (k > sum || ind < 0)
//         return false;
//     if (dp[ind][k] != -1)
//         return dp[ind][k];
//     bool take = util(nums, ind - 1, k + nums[ind], sum, dp);
//     bool dont_take = util(nums, ind - 1, k, sum, dp);
//     return dp[ind][k] = take || dont_take;
// }
// int util(vector<int> &nums, int ind, int k, int sum, vector<vector<int>> &dp)
// {
//     if (k == 0)
//         return true;
//     if (k < 0 || ind == nums.size())
//         return false;
//     if (dp[ind][k] != -1)
//         return dp[ind][k];
//     int take = util(nums, ind + 1, k + nums[ind], sum, dp);
//     int dont_take = util(nums, ind + 1, k, sum, dp);
//     return dp[ind][k] = take || dont_take;
// }
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (auto i : nums)
        sum += i;
    if (sum % 2 != 0)
        return false;
    // vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, 0));
    // vector<vector<int>> dp(n + 1, vector<int>(sum/2 + 1, -1));
    // return util(nums, nums.size()-1, 0, sum/2, dp);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < sum / 2 + 1; j++)
    //     {
    //         if (j == 0)
    //             dp[i][j] = 1;
    //         else if (i == 0)
    //         {
    //             if (nums[i] <= sum / 2)
    //                 dp[i][nums[i]] = 1;
    //         }
    //         else
    //         {
    //             int dont_take = dp[i - 1][j];
    //             int take = (j - nums[i] < 0) ? 0 : dp[i - 1][j - nums[i]];
    //             dp[i][j] = take || dont_take;
    //         }
    //     }
    // }
    // return dp[n - 1][sum / 2];

    vector<int> prev(sum / 2 + 1, 0);
    vector<int> curr(sum / 2 + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sum / 2 + 1; j++)
        {
            if (j == 0)
                curr[j] = 1;
            else if (i == 0)
            {
                if (nums[i] <= sum / 2)
                    curr[nums[i]] = 1;
            }
            else
            {
                int dont_take = prev[j];
                int take = (j - nums[i] < 0) ? 0 : prev[j - nums[i]];
                curr[j] = take || dont_take;
            }
        }
        prev=curr;
    }
    return curr[sum / 2];
}
int main()
{
    vector<int> nums = {1, 2,5};
    cout << canPartition(nums);
}