#include <bits/stdc++.h>
using namespace std;
int util(vector<int> &arr, int difference, int ind, int prev, vector<vector<int>> &dp)
{
    if (ind == arr.size())
        return 0;
    // prev=prev+1;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int res = 0;
    if (prev == -1 || arr[prev] + difference == arr[ind])
    {
        res = 1 + util(arr, difference, ind + 1, ind, dp);
    }
    res = max(res, util(arr, difference, ind + 1, prev, dp));
    return dp[ind][prev + 1] = res;
}
int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // return util(arr,difference,0,-1,dp);
    for (int ind = n - 1; ind >= 0; ind++)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int res = 0;
            if (prev == -1 || arr[prev] + difference == arr[ind])
            {
                res = 1 + dp[ind + 1][ind];
            }
            res = max(res, dp[ind + 1][prev + 1]);
            dp[ind][prev + 1] = res;
        }
    }
    return dp[0][0];
}
int main()
{
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    cout << longestSubsequence(arr, -2);
}