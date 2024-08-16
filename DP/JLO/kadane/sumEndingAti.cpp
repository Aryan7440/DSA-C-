#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {3, -7, 4, 2, -1, 4};
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
        dp[i] = nums[i];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + nums[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}