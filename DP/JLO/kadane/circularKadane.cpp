#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int res = min(0, nums[0]);
    int t_sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = min(nums[i], dp[i - 1] + nums[i]);
        res = min(res, dp[i]);
        t_sum += nums[i];
    }
    cout << t_sum - res << endl;

    return 0;
}