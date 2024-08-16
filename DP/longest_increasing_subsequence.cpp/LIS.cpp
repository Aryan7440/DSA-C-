#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &nums, int ind, int prev_ind, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        return dp[ind][prev_ind + 1] = max(1 + util(nums, ind + 1, ind, dp), 0 + util(nums, ind + 1, prev_ind, dp));
    }
    return dp[ind][prev_ind + 1] = util(nums, ind + 1, prev_ind, dp);
}
void lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n+1 , vector<int>(n + 1, 0));
    // vector<vector<int>> dp(n , vector<int>(n + 1, -1));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind-1; prev_ind >= -1; prev_ind--)
        {
            if (prev_ind == -1 || nums[ind] > nums[prev_ind])
            {
                dp[ind][prev_ind + 1] = max(1 + dp[ind+1][ind+1], dp[ind+1][prev_ind+1]);
            }
            else dp[ind][prev_ind + 1] =dp[ind+1][prev_ind+1];
        }
    }
    // return util(nums, 0, -1, dp);
    // util(nums, 0, -1, dp);
    cout<< dp[1][0]<<endl;
    for(auto i:dp)
    {
        for(auto j:i)cout<<j<<"   ";
        cout<<endl;
    }
}
int main()
{
    vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};//2  4  5  6  7  12
    lengthOfLIS(nums);
}