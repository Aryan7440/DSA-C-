#include <bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> par(n, 1);
    for (int i = 0; i < n; i++)
        par[i] = i;
    int maxi = -1;
    int last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                par[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = max(dp[i], maxi);
            last = i;
        }
    }
    vector<int> ans;
    ans.push_back(nums[last]);
    while (par[last] != last)
    {
        last = par[last];
        ans.push_back(nums[last]);
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}