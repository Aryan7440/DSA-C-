#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    count[i] = count[i] + count[j];
                }
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxi == dp[i])
            ans += count[i];
    }
    return ans;
}
int main()
{
    vector<int> nums={1,2,4,3,5,4,7,2};
    cout<<findNumberOfLIS(nums);
}