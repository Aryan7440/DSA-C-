#include <bits/stdc++.h>
using namespace std;

int MinDiff(vector<int> &nums, int ind, int S1, int TotalSum, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return abs(TotalSum - 2 * S1);
    if (dp[ind][S1] != -1)
        return dp[ind][S1];
    return dp[ind][S1] = min(MinDiff(nums, ind + 1, S1 + nums[ind], TotalSum, dp), MinDiff(nums, ind + 1, S1, TotalSum, dp));
}
int main()
{
    vector<int> nums = {-36, 36};
    int TotalSum = 0;
    for (auto i : nums)
        TotalSum += i;
    vector<vector<int>> dp(nums.size(), vector<int>(TotalSum + 1, -1));
    cout << MinDiff(nums, 0, 0, TotalSum, dp);
}